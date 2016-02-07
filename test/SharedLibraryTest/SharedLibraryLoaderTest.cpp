#include "SharedLibraryLoaderTest.h"
#include <stdexcept>
	using ::std::runtime_error;

TEST_F(SharedLibLoaderWithValidPath, LoadsCorrectly) {
	ASSERT_TRUE(_sll.GetHandle() != NULL);
}

TEST_F(SharedLibLoaderWithValidPath, GetValidFunctionPointer) {
	ASSERT_TRUE(_sll.GetFunctionPointer("create_object") != NULL);
}

TEST_F(SharedLibLoaderWithValidPath, GetInvalidFunctionPointerThrowsException) {
	try {
		_sll.GetFunctionPointer("foobar");
		FAIL();
	} catch (...) {
	}
	
}

TEST_F(SharedLibLoaderWithInvalidPath, LoadThrowsException) {
	try {
		_sll.Load();
		FAIL();
	} catch (const runtime_error& e) {  }
}

