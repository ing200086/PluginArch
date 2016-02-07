#include "Plugin.h"

void GenericPlugin::SetEngineVersionFunction(ISharedLibraryLoader &loader) {
	void *funcAddress
		= loader.GetFunctionPointer("getEngineVersion");

	_getEngineVersionAddress
		= reinterpret_cast<GetEngineVersionFunction *>(funcAddress);
}

void GenericPlugin::SetRegisterPluginFunction(ISharedLibraryLoader &loader) {
	void *funcAddress
		= loader.GetFunctionPointer("registerPlugin");

	_registerPluginAddress
		= reinterpret_cast<RegisterPluginFunction *>(funcAddress);
}

GenericPlugin::GenericPlugin(ISharedLibraryLoader &loader) {
	loader.Load();
	SetEngineVersionFunction(loader);
	SetRegisterPluginFunction(loader);
}

int GenericPlugin::GetEngineVersion() {
	return this->_getEngineVersionAddress();
}

void GenericPlugin::RegisterPlugin(IPluginRegistrationServices &registrationServices) {
	this->_registerPluginAddress(registrationServices);
}