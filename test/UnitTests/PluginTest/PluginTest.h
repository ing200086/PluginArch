#ifndef __PLUGIN_TEST_H__
#define __PLUGIN_TEST_H__

#include "Plugin.h"
#include "PluginTestMocks.h"
#include "gmock/gmock.h"
	using ::testing::Test;
	using ::testing::Return;

class PluginTestFixture: public Test {
protected:
	void SetUpMockLibraryLoader() {
		void *_getEngineVersionAdd = reinterpret_cast<void *>(mock_getEngineVersion);
		void *_registerPluginAdd = reinterpret_cast<void *>(mock_RegisterPluginFunction);

		EXPECT_CALL(_libLoader, Load())
			.Times(1);
		EXPECT_CALL(_libLoader, GetFunctionPointer("getEngineVersion"))
			.Times(1)
			.WillOnce(Return(_getEngineVersionAdd));
		EXPECT_CALL(_libLoader, GetFunctionPointer("registerPlugin"))
			.Times(1)
			.WillOnce(Return(_registerPluginAdd));
		}
public:
	MockSharedLibraryLoader _libLoader;
	MockPluginRegistrationService _pluginRegistry;
	GenericPlugin *_plugin;

	PluginTestFixture() {}
	~PluginTestFixture() {}

	virtual void SetUp() {
		SetUpMockLibraryLoader();
		// SetUpMockPluginRegistrationService();

		_plugin = new GenericPlugin(_libLoader);
	}

	virtual void TearDown() {

	}
};

#endif