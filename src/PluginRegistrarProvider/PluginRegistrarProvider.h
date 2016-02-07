#ifndef __PLUGIN_REGSTRAR_PROVIDER_H__
#define __PLUGIN_REGSTRAR_PROVIDER_H__

#include <string>
	using ::std::string;
#include <map>
	using ::std::map;

class IPlugin {
};

class IPluginRegistrarService {
public:
	virtual void Register(IPlugin &plugin) =0;
};


class PluginRegistrarProvider {
	typedef map<string, IPluginRegistrarService*> RegistrarMap;
	RegistrarMap _pluginRegistrarMap;

public:
	void AddRegistrar(const string &serviceType, IPluginRegistrarService &reg) {
		_pluginRegistrarMap.insert(RegistrarMap::value_type(serviceType, &reg));
	}

	IPluginRegistrarService *For(const string &serviceType) {
		return _pluginRegistrarMap[serviceType];
	}
};

#endif