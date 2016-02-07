#ifndef __KERNEL_H__
#define __KERNEL_H__

#include <string>
	using ::std::string;
#include <vector>
	using ::std::vector;
#include <algorithm>
	using ::std::find;

class IPluginForKernel {
public:
	virtual string ServiceType() =0;
};

class IProviderStorageService {
public:
	virtual void addService(IPluginForKernel &plugin)=0;
};

class IPluginRegistrarFactory {
public:
	virtual IProviderStorageService *forService(const string &serviceType) =0;
};

class Kernel {
protected:
	vector<string> _loadedPlugins;
	IPluginRegistrarFactory *_regFactory;
	
	bool IsInLoadedPluginVector(const string &pluginName) {
		return (find(_loadedPlugins.begin(), _loadedPlugins.end(), pluginName) != _loadedPlugins.end());
	}
public:
	Kernel(IPluginRegistrarFactory &regFactory) {
		_regFactory = &regFactory;
	}

	void loadPlugin(const string &pluginName, IPluginForKernel &plugin) {
		_regFactory->forService(plugin.ServiceType());
		// ->addService(plugin);
		_loadedPlugins.push_back(pluginName);
	}

	bool hasPlugin(const string &pluginName) {
		return IsInLoadedPluginVector(pluginName);
	}
};


#endif