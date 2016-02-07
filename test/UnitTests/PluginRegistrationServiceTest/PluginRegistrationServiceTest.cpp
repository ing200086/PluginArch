#include "PluginRegistrationServiceTest.h"
	using ::testing::Eq;

TEST_F(PluginRegistrationServiceWithRegisteredPlugin, HasPlugin) {
	ASSERT_TRUE(_prs.Has(_plugin));
}

TEST_F(PluginRegistrationServiceWithRegisteredPlugin, ReturnPluginFromPluginID) {
	ASSERT_THAT(_prs.Get(_pluginID), Eq(&_plugin));
}