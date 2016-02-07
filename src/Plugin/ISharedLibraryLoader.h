#ifndef __I_SHARED_LIBRARY_LOADER_H__
#define __I_SHARED_LIBRARY_LOADER_H__

#include <string>
	using ::std::string;

class ISharedLibraryLoader {
public:
	typedef void* Handletype;

	ISharedLibraryLoader() {}
	virtual ~ISharedLibraryLoader() {}

	virtual void Load() =0;

	virtual void Unload() =0;

	virtual Handletype GetHandle() =0;

	virtual void *GetFunctionPointer(const string &functionName) =0;
};

#endif