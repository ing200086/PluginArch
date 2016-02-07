#ifndef __PLUGIN_REGISTRATION_SERIVCE_H__
#define __PLUGIN_REGISTRATION_SERIVCE_H__

#include <string>
	using ::std::string;
#include <map>
	using ::std::map;

template <class PluginStored>
class PluginRegistrationService {
	using PluginMap = map<string, PluginStored*>;
	PluginMap _registeredPlugins;
	
public:
	void Register(PluginStored &plugin) {
		_registeredPlugins.insert(
			typename PluginMap::value_type(plugin.ID(), &plugin));
	}

	// bool Has(PluginStored &plugin) {
	// 	return (_registeredPlugins[plugin.ID()] != NULL);
	// }

	PluginStored *Get(const string ID) {
		return _registeredPlugins[ID];
	}
};

#endif