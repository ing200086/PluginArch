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
	string _otherPluginID = "PluginB";
	string _pluginNotLoadedID = "PluginC";

	PluginRegistrationService<StubPluginToRegister> _prs;
	StubPluginToRegister _plugin;
	StubPluginToRegister _otherPlugin;
	StubPluginToRegister _pluginNotLoaded;

public:
	PluginRegistrationServiceWithRegisteredPlugin() {
		_plugin.SetID(_pluginID);
		_otherPlugin.SetID(_otherPluginID);
		_pluginNotLoaded.SetID(_pluginNotLoadedID);
	}
	virtual ~PluginRegistrationServiceWithRegisteredPlugin() {}

	virtual void SetUp() {
		_prs.Register(_plugin);
		_prs.Register(_otherPlugin);
	}

	virtual void TearDown() {}

};

#endif