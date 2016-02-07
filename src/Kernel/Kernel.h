#ifndef __KERNEL_H__
#define __KERNEL_H__

#include "IPluginRegistrarProvider.h"

#include <string>
	using ::std::string;
#include <vector>
	using ::std::vector;

class Kernel {
protected:
	vector<string> _loadedPlugins;
	IPluginRegistrarProvider *_regFactory;
	
	bool IsInLoadedPluginVector(const string &pluginName);
public:
	Kernel(IPluginRegistrarProvider &regFactory);

	void loadPlugin(IPluginToRegister &plugin);
	// bool hasPlugin(const string &pluginName);

	void listGraphicsDrivers(string &output) {
		output = "woo";
	}
};


#endif