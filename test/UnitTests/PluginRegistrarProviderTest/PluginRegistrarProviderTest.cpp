#include "PluginRegistrarProviderTest.h"
	using ::testing::Eq;
	using ::testing::Return;

TEST_F(PluginRegistrarProviderWithRegistrationServiceAdded, ReturnsSameRegistrarFromProvider) {
	EXPECT_CALL(_MockRegistrationService, AcceptsService())
		.Times(1)
		.WillOnce(Return("WidgetPlugin"));

	_regProvider->AddRegistrar(_MockRegistrationService);
	ASSERT_THAT(_regProvider->For("WidgetPlugin"), 
					Eq(&_MockRegistrationService));
}