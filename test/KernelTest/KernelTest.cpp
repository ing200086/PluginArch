#include "KernelTest.h"
	using ::testing::_;
	using ::testing::Return;

TEST_F(KernelLoadedWithMockPlugin, HasPluginWhichIsLoaded) {
	EXPECT_CALL(_regFactory, forService(_))
			.Times(1);
	KernelLoadsPlugin();
	ASSERT_TRUE(_pluginKernel->hasPlugin(_pluginNameLoaded));
}

TEST_F(KernelLoadedWithMockPlugin, HasOnlyLoadedPlugin) {
	EXPECT_CALL(_regFactory, forService(_))
			.Times(1);
	KernelLoadsPlugin();
	ASSERT_FALSE(_pluginKernel->hasPlugin(_pluginNameNotLoaded));
}

TEST_F(KernelLoadedWithMockPlugin, RegistersValidService) {
	EXPECT_CALL(_regFactory, forService("ValidService"))
			.Times(1)
			.WillOnce(Return(new MockProviderStorageService()));
	EXPECT_CALL(_plugin, ServiceType())
			.Times(1)
			.WillOnce(Return("ValidService"));

	KernelLoadsPlugin();
}

ACTION(throwServiceNotHandled) {
	throw ::std::exception();
}

TEST_F(KernelLoadedWithMockPlugin, RegistersInvalidServiceThrowsException) {
	EXPECT_CALL(_regFactory, forService("ServiceUnhandledByRegistrationFactory"))
			.Times(1)
			.WillOnce(throwServiceNotHandled());
	EXPECT_CALL(_plugin, ServiceType())
			.Times(1)
			.WillOnce(Return("ServiceUnhandledByRegistrationFactory"));

	try {
		KernelLoadsPlugin();
		FAIL();
	} catch (...) {

	}
	
}