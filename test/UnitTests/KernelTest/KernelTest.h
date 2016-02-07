#ifndef __KERNEL_TEST_H__
#define __KERNEL_TEST_H__

#include "Kernel.h"
#include "KernelTestMocks.h"
#include "gmock/gmock.h"
	using ::testing::Test;

class KernelLoadedWithMockPlugin: public Test {
public:
	string _pluginNameLoaded = "A";
	string _pluginNameNotLoaded = "B";
	MockStoragePlugin _plugin;

	MockPluginRegistrarFactory _regFactory;
	Kernel *_pluginKernel;

protected:
	void KernelLoadsPlugin() {
		_pluginKernel->loadPlugin(_pluginNameLoaded, _plugin);
	}

public:
	KernelLoadedWithMockPlugin() {	}
	virtual ~KernelLoadedWithMockPlugin() {  }

	virtual void SetUp() {
		_pluginKernel = new Kernel(_regFactory);
	}

	virtual void TearDown() {  }

};

#endif