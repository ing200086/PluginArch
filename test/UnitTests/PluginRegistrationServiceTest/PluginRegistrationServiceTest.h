#ifndef __PLUGIN_REGISTRATION_SERIVCE_TEST_H__
#define __PLUGIN_REGISTRATION_SERIVCE_TEST_H__

#include "PluginRegistrationService.h"
#include "PluginRegistrationServiceTestMocks.h"

#include "gmock/gmock.h"
	using ::testing::Return;
	using ::testing::Test;

#include <string>
	using ::std::string;

class PluginRegistrationServiceWithRegisteredPlugin: public Test {
protected:
	string _pluginID = "PluginA";
	PluginRegistrationService<StubPluginToRegister> _prs;
	StubPluginToRegister _plugin;

public:
	PluginRegistrationServiceWithRegisteredPlugin() {}
	virtual ~PluginRegistrationServiceWithRegisteredPlugin() {}

	virtual void SetUp() {
		_prs.Register(_plugin);
	}

	virtual void TearDown() {}

};

#endif