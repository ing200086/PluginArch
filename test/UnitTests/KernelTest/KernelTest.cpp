#include "KernelTest.h"
	using ::testing::_;
	using ::testing::Eq;
	using ::testing::Return;

#include <string>
	using ::std::string;

TEST_F(KernelLoadedWithMockPlugin, HasPluginWhichIsLoaded) {
	string logString;
	MockPluginToRegister _plugin;

	EXPECT_CALL(_regService, Register(_))
			.Times(1);
	EXPECT_CALL(_regFactory, For(_))
			.Times(1)
			.WillOnce(Return(&_regService));

	(*_pluginKernel).loadPlugin(_plugin);
	// ASSERT_TRUE(_pluginKernel->hasPlugin(_pluginNameLoaded));
}

TEST_F(KernelLoadedWithMockPlugin, ListsGraphicsDrivers) {
	EXPECT_CALL(_regService, ListRegistered())
			.Times(1)
			.WillOnce(Return("woo"));
	EXPECT_CALL(_regFactory, For("GraphicsDrivers"))
			.Times(1)
			.WillOnce(Return(&_regService));

	(*_pluginKernel).listGraphicsDrivers(logString);

	ASSERT_THAT(logString, Eq("woo"));
}