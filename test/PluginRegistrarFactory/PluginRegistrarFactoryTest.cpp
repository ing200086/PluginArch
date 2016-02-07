#include "PluginRegistrarFactoryTest.h"

TEST(ConstructRegistrarFactory, AddRegistrar) {
	PluginRegistrarFactory _regFactory;
	MockPluginRegistrar _reg;

	_regFactory.AddRegistrar("WidgetPlugin", _reg);
}

TEST(ConstructRegistrarFactory, ReturnRegistrarFromFactory) {
	PluginRegistrarFactory _regFactory;
	MockPluginRegistrar _reg;

	_regFactory.AddRegistrar("WidgetPlugin", _reg);

	IPluginRegistrar *_widgetRegistrar;

	_widgetRegistrar = _regFactory.For("WidgetPlugin");

	ASSERT_THAT(&_reg, Eq(_widgetRegistrar));
}