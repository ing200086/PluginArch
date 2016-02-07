#ifndef __SHARED_LIBRARY_LOADER_H__
#define __SHARED_LIBRARY_LOADER_H__

#include "ISharedLibraryLoader.h"
#include <string>
	using ::std::string;

class SharedLibraryLoader : public ISharedLibraryLoader {
protected:
	ISharedLibraryLoader::Handletype _handle;
	string _path;

	bool HandleIsSet();

	virtual void LoadObj();

	virtual void UnloadObj();

public:
	SharedLibraryLoader() : _handle(NULL), _path("") {}

	virtual ~SharedLibraryLoader() { Unload(); }

	virtual void Load() { LoadObj(); }

	virtual void Unload();

	virtual void SetPath(const string& path) { _path = path; }

	virtual ISharedLibraryLoader::Handletype GetHandle();

	virtual void *GetFunctionPointer(const string &functionName);
};

#endif