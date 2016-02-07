#ifndef __PLUGIN_H__
#define __PLUGIN_H__

#include "ISharedLibraryLoader.h"

class IPluginRegistrationServices { };

class GenericPlugin{
public:
	typedef int GetEngineVersionFunction();
	typedef void RegisterPluginFunction(IPluginRegistrationServices &registrationServices);
	
protected:
	GetEngineVersionFunction *_getEngineVersionAddress;
	RegisterPluginFunction *_registerPluginAddress;

	void SetEngineVersionFunction(ISharedLibraryLoader &loader);
	void SetRegisterPluginFunction(ISharedLibraryLoader &loader);

public:
	GenericPlugin(ISharedLibraryLoader &loader);

	int GetEngineVersion();
	void RegisterPlugin(IPluginRegistrationServices &registrationServices);
};

#endif