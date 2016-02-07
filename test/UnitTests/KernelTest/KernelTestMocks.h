#ifndef __KERNEL_TEST_MOCKS_H__
#define __KERNEL_TEST_MOCKS_H__

#include "Kernel.h"
#include "gmock/gmock.h"

class IPluginToRegister {};
class IPluginRegistrarService {};

class MockPluginToRegister: public IPluginToRegister {
};

class MockProviderStorageService: public IPluginRegistrarService {
};

class MockPluginRegistrarFactory: public IPluginRegistrarProvider {
public:
	MOCK_METHOD1(For, IPluginRegistrarService *(IPluginToRegister &plugin));
};

#endif