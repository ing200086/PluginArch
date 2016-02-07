#ifndef __PLUGIN_TEST_MOCKS_H__
#define __PLUGIN_TEST_MOCKS_H__

#include "ISharedLibraryLoader.h"
#include "gmock/gmock.h"

class MockSharedLibraryLoader : public ISharedLibraryLoader {
public:
	MOCK_METHOD0(Load, void());
	MOCK_METHOD0(Unload, void());
	MOCK_METHOD0(GetHandle, ISharedLibraryLoader::Handletype());
	MOCK_METHOD1(GetFunctionPointer, void*(const string &functionName));
};

class MockPluginRegistrationService: public IPluginRegistrationServices {  };

int mock_getEngineVersion() { return 1; }

void mock_RegisterPluginFunction(IPluginRegistrationServices &registerService) { }

#endif