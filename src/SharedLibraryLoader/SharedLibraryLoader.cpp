#include "SharedLibraryLoader.h"
#include <stdexcept>
	using ::std::runtime_error;
#include <dlfcn.h>

void SharedLibraryLoader::UnloadObj() {
	int closeResult = ::dlclose(_handle);
	if (closeResult == 0) _handle = NULL;
}

void SharedLibraryLoader::LoadObj() {
	if (!HandleIsSet()) _handle = ::dlopen(_path.c_str(), RTLD_NOW);
	if (!HandleIsSet()) throw runtime_error("Plugin not found.");
}

bool SharedLibraryLoader::HandleIsSet() {
	return (_handle != NULL);
}

void SharedLibraryLoader::Unload() {
	if (HandleIsSet()) UnloadObj();
	if (HandleIsSet()) throw runtime_error("Unable to unload plugin.");	
}

ISharedLibraryLoader::Handletype SharedLibraryLoader::GetHandle() {
	if (!HandleIsSet()) return NULL;

	return _handle;
}

void *SharedLibraryLoader::GetFunctionPointer(const string &functionName) {
	::dlerror();

	void *funcAddress = ::dlsym(GetHandle(), functionName.c_str());
	if (::dlerror() != NULL) throw runtime_error("Unable to find exported function.");

	return funcAddress;
}