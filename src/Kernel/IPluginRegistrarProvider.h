#ifndef __I_PLUGIN_REGISTRAR_PROVIDER_H__
#define __I_PLUGIN_REGISTRAR_PROVIDER_H__

class IPluginToRegister;
class IPluginRegistrarService;

class IPluginRegistrarProvider {
public:
	virtual IPluginRegistrarService *For(IPluginToRegister &plugin) =0;
};

#endif