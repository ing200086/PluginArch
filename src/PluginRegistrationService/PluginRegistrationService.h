#ifndef __PLUGIN_REGISTRATION_SERIVCE_H__
#define __PLUGIN_REGISTRATION_SERIVCE_H__

#include <string>
	using ::std::string;

template <class PluginStored>
class PluginRegistrationService {
	PluginStored *_pluginToReturn;
public:
	void Register(PluginStored &plugin) {
		plugin.ID();
		_pluginToReturn = &plugin;
	}

	bool Has(PluginStored &plugin) {
		return true;
	}

	PluginStored *Get(const string ID) {
		return _pluginToReturn;
	}
};

#endif