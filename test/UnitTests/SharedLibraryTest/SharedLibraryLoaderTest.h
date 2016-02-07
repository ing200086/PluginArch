#ifndef __SHARED_LIBRARY_LOADER_TEST_H__
#define __SHARED_LIBRARY_LOADER_TEST_H__

#include "SharedLibraryLoader.h"
#include "gmock/gmock.h"
	using ::testing::Test;

class SharedLibLoaderWithValidPath: public Test {
public:
	string _path;
	SharedLibraryLoader _sll;
	
	SharedLibLoaderWithValidPath() { _path = "/home/daniel/Workspace/libObj.so"; }
	~SharedLibLoaderWithValidPath() {}

	virtual void SetUp() {
		_sll.SetPath(_path);
		_sll.Load();
	}

	virtual void TearDown() {
		_sll.Unload();
	}
};

class SharedLibLoaderWithInvalidPath: public SharedLibLoaderWithValidPath {
public:
	SharedLibLoaderWithInvalidPath() { _path = "/home/daniel/Workspace/nonExistantObj.so"; }

	virtual void SetUp() {
		_sll.SetPath(_path);
	}
};

#endif

