#include "PluginRegistrarProviderTest.h"
	using ::testing::Eq;

TEST_F(PluginRegistrarProviderWithRegistrationServiceAdded, ReturnsSameRegistrarFromProvider) {
	ASSERT_THAT(&_reg, Eq(_regProvider->For("WidgetPlugin")));
}