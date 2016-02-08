#include "gmock/gmock.h"
  using ::testing::Eq;
  
#include <string>
  using ::std::string;
  
inline bool FileExists (const string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}
  
TEST(UserCase01, PluginFileExists) {
  ASSERT_TRUE(FileExists("../OpenGLPlugin.so"));
}
