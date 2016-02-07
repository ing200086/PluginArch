#ifndef __PLUGIN_REGISTRATION_SERVICE_TEST_MOCKS_H__
#define __PLUGIN_REGISTRATION_SERVICE_TEST_MOCKS_H__

#include "gmock/gmock.h"

class StubPluginToRegister {
public:
	string ID() { return "pluginA"; }
};


#endif