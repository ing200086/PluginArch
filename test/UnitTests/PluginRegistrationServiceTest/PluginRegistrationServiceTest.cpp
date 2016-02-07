#include "PluginRegistrationServiceTest.h"
	using ::testing::Eq;

// TEST_F(PluginRegistrationServiceWithRegisteredPlugin, HasPlugin) {
// 	ASSERT_TRUE(_prs.Has(_plugin));
// }

// TEST_F(PluginRegistrationServiceWithRegisteredPlugin, DoesNotHavePluginNotLoaded) {
// 	ASSERT_FALSE(_prs.Has(_pluginNotLoaded));
// }

TEST_F(PluginRegistrationServiceWithRegisteredPlugin, ReturnPluginFromPluginID) {
	ASSERT_THAT(_prs.Get(_pluginID), Eq(&_plugin));
}

TEST_F(PluginRegistrationServiceWithRegisteredPlugin, ReturnsMultiplePlugins) {
	ASSERT_THAT(_prs.Get(_otherPluginID), Eq(&_otherPlugin));
}