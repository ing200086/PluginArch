#ifndef __PLUGIN_REGISTRAR_FACTORY_TEST_H__
#define __PLUGIN_REGISTRAR_FACTORY_TEST_H__

#include "PluginRegistrarFactory.h"
#include "gmock/gmock.h"
	using ::testing::Eq;

#include <string>
	using ::std::string;
#include <map>
	using ::std::map;

class MockPluginRegistrar: public IPluginRegistrar {
public:
	MOCK_METHOD1(Register, void(IPlugin &plugin));
};

#endif