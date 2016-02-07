#include "Kernel.h"

#include <algorithm>
	using ::std::find;

Kernel::Kernel(IPluginRegistrarProvider &regFactory) {
	_regFactory = &regFactory;
}

bool Kernel::IsInLoadedPluginVector(const string &pluginName) {
	return (find(_loadedPlugins.begin(),
					_loadedPlugins.end(),
					pluginName) != _loadedPlugins.end());
}

void Kernel::loadPlugin(IPluginToRegister &plugin) {
	_regFactory->For(plugin.ID())->Register(plugin);
	// _loadedPlugins.push_back(pluginName);
}

// bool Kernel::hasPlugin(const string &pluginName) {
// 	return IsInLoadedPluginVector(pluginName);
// }