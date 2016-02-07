#ifndef __KERNEL_TEST_H__
#define __KERNEL_TEST_H__

#include "Kernel.h"
#include "KernelTestMocks.h"
#include "gmock/gmock.h"
	using ::testing::Test;

class KernelLoadedWithMockPlugin: public Test {
public:
	MockPluginRegistrarFactory _regFactory;
	Kernel *_pluginKernel;

protected:

public:
	KernelLoadedWithMockPlugin() {	}
	virtual ~KernelLoadedWithMockPlugin() {  }

	virtual void SetUp() {
		_pluginKernel = new Kernel(_regFactory);
	}

	virtual void TearDown() {  }

};

#endif