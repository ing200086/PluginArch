#ifndef __PLUGIN_REGSTRAR_FACTORY_H__
#define __PLUGIN_REGSTRAR_FACTORY_H__

#include <string>
	using ::std::string;
#include <map>
	using ::std::map;

class IPlugin {
};

class IPluginRegistrar {
public:
	virtual void Register(IPlugin &plugin) =0;
};


class PluginRegistrarFactory {
	typedef map<string, IPluginRegistrar*> RegistrarMap;
	RegistrarMap _pluginRegistrarMap;

public:
	void AddRegistrar(const string &serviceType, IPluginRegistrar &reg) {
		_pluginRegistrarMap.insert(RegistrarMap::value_type(serviceType, &reg));
	}

	IPluginRegistrar *For(const string &serviceType) {
		return _pluginRegistrarMap[serviceType];
	}
};

#endif