#ifndef __PLUGIN_REGISTRAR_PROVIDER_TEST_MOCK_H__
#define __PLUGIN_REGISTRAR_PROVIDER_TEST_MOCK_H__

#include "PluginRegistrarProvider.h"
#include "gmock/gmock.h"

class MockPluginRegistrarService: public IPluginRegistrarService {
public:
	MOCK_METHOD0(AcceptsService, string());
};

#endif