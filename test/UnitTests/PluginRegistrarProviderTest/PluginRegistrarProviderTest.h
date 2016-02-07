#ifndef __PLUGIN_REGISTRAR_PROVIDER_TEST_H__
#define __PLUGIN_REGISTRAR_PROVIDER_TEST_H__

#include "PluginRegistrarProvider.h"
#include "PluginRegistrarProviderTestMocks.h"
#include "gmock/gmock.h"
	using ::testing::Test;

class PluginRegistrarProviderWithRegistrationServiceAdded: public Test {
public:
	PluginRegistrarProvider *_regProvider;
	MockPluginRegistrarService _MockRegistrationService;

	PluginRegistrarProviderWithRegistrationServiceAdded() {}
	virtual ~PluginRegistrarProviderWithRegistrationServiceAdded() {}

	virtual void SetUp() {
		_regProvider = new PluginRegistrarProvider();
		
	}

	virtual void TearDown() {}
};

#endif