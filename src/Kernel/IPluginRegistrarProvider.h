#ifndef __I_PLUGIN_REGISTRAR_PROVIDER_H__
#define __I_PLUGIN_REGISTRAR_PROVIDER_H__

#include <string>
	using ::std::string;

class IPluginToRegister {
public:
	virtual string ID();
};

class IPluginRegistrarService {
public:
	virtual void Register(IPluginToRegister &plugin) =0;
	virtual string ListRegistered() =0;
};

class IPluginRegistrarProvider {
public:
	virtual IPluginRegistrarService *For(const string &pluginService) =0;
};

#endif