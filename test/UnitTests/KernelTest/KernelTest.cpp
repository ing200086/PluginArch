#include "KernelTest.h"
	using ::testing::_;
	using ::testing::Return;

TEST_F(KernelLoadedWithMockPlugin, HasPluginWhichIsLoaded) {
	MockPluginToRegister _plugin;
	EXPECT_CALL(_regFactory, For(_))
			.Times(1);
	(*_pluginKernel).loadPlugin(_plugin);
	// ASSERT_TRUE(_pluginKernel->hasPlugin(_pluginNameLoaded));
}

TEST_F(KernelLoadedWithMockPlugin, HasOnlyLoadedPlugin) {
	// EXPECT_CALL(_regFactory, For(_))
	// 		.Times(1);
	// KernelLoadsPlugin();
	// ASSERT_FALSE(_pluginKernel->hasPlugin(_pluginNameNotLoaded));
}

// TEST_F(KernelLoadedWithMockPlugin, RegistersValidService) {
// 	// EXPECT_CALL(_regFactory, For("ValidService"))
// 	// 		.Times(1)
// 	// 		.WillOnce(Return(new MockProviderStorageService()));
// 	// EXPECT_CALL(_plugin, ServiceType())
// 	// 		.Times(1)
// 	// 		.WillOnce(Return("ValidService"));

// 	KernelLoadsPlugin();
// }

// ACTION(throwServiceNotHandled) {
// 	throw ::std::exception();
// }

// TEST_F(KernelLoadedWithMockPlugin, RegistersInvalidServiceThrowsException) {
// 	// EXPECT_CALL(_regFactory, For("ServiceUnhandledByRegistrationFactory"))
// 	// 		.Times(1)
// 	// 		.WillOnce(throwServiceNotHandled());
// 	// EXPECT_CALL(_plugin, ServiceType())
// 	// 		.Times(1)
// 	// 		.WillOnce(Return("ServiceUnhandledByRegistrationFactory"));

// 	try {
// 		KernelLoadsPlugin();
// 		FAIL();
// 	} catch (...) {

// 	}
	
// }