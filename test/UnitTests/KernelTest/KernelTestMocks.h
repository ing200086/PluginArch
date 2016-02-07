#ifndef __KERNEL_TEST_MOCKS_H__
#define __KERNEL_TEST_MOCKS_H__

#include "Kernel.h"
#include "gmock/gmock.h"

class MockPluginToRegister: public IPluginToRegister {
};

class MockPluginRegistrationService: public IPluginRegistrarService {
public:
	MOCK_METHOD1(Register, void(IPluginToRegister &plugin));
	MOCK_METHOD0(ListRegistered, string());
};

class MockPluginRegistrarFactory: public IPluginRegistrarProvider {
public:
	MOCK_METHOD1(For, IPluginRegistrarService *(const string &pluginService));
};

#endif