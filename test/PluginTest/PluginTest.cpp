#include "PluginTest.h"
	using ::testing::Eq;

TEST_F(PluginTestFixture, GetsEngineVersion) {
	ASSERT_THAT(_plugin->GetEngineVersion(), Eq(1));
}

TEST_F(PluginTestFixture, RegisterKernel) {
	_plugin->RegisterPlugin(_pluginRegistry);
}