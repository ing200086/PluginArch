#ifndef __KERNEL_TEST_MOCKS_H__
#define __KERNEL_TEST_MOCKS_H__

// #include "ISharedLibraryLoader.h"
#include "Kernel.h"
#include "gmock/gmock.h"

// class MockSharedLibraryLoader : public ISharedLibraryLoader {
// public:
// 	MOCK_METHOD0(Load, void());
// 	MOCK_METHOD0(Unload, void());
// 	MOCK_METHOD0(GetHandle, ISharedLibraryLoader::Handletype());
// 	MOCK_METHOD1(GetFunctionPointer, void*(const string &functionName));
// };

class MockStoragePlugin: public IPluginForKernel {
public:
	MOCK_METHOD0(ServiceType, string());
};

class MockProviderStorageService: public IPluginRegistrarService {
public:
	MOCK_METHOD1(addService, void(IPluginForKernel &plugin));
};

class MockPluginRegistrarFactory: public IPluginRegistrarProvider {
public:
	MOCK_METHOD1(For, IPluginRegistrarService *(const string &serviceType));
};

#endif