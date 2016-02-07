#ifndef __PLUGIN_REGISTRATION_SERVICE_TEST_MOCKS_H__
#define __PLUGIN_REGISTRATION_SERVICE_TEST_MOCKS_H__

#include "gmock/gmock.h"

class StubPluginToRegister {
	string _myID;
public:
	void SetID(const string &ID) {
		_myID = ID;
	}

	string ID() { return _myID; }
};


#endif