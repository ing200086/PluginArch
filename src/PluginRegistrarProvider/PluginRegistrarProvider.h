#ifndef __PLUGIN_REGSTRAR_PROVIDER_H__
#define __PLUGIN_REGSTRAR_PROVIDER_H__

#include <string>
	using ::std::string;
#include <map>
	using ::std::map;

class IPluginRegistrarService {
public:
	virtual string AcceptsService() =0;
};


class PluginRegistrarProvider {
	typedef map<string, IPluginRegistrarService*> RegistrarMap;
	RegistrarMap _pluginRegistrarMap;

public:
	void AddRegistrar(IPluginRegistrarService &reg) {
		_pluginRegistrarMap.insert(
			RegistrarMap::value_type(reg.AcceptsService(), &reg)
			);
	}

	IPluginRegistrarService *For(const string &serviceType) {
		return _pluginRegistrarMap[serviceType];
	}
};

#endif