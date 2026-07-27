#include "FuckEntityPush.h"

#include "Config.h"
#include "ll/api/mod/RegisterHelper.h"
#include "ll/api/Config.h"
#include "ll/api/utils/ErrorUtils.h"


namespace FuckEntityPush {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

Config& Entry::getConfig() { return mConfig.value(); }

bool Entry::load() {
    bool res{};
    mConfig.emplace();
    const auto& configFilePath = getInstance().getSelf().getConfigDir() / "config.json";
    try {
        res = ll::config::loadConfig(*mConfig, configFilePath);
    } catch (...) {
        ll::error_utils::printCurrentException(getSelf().getLogger());
        res = false;
    }
    if (!res) ll::config::saveConfig(*mConfig, configFilePath);
    return true;
}

bool Entry::enable() {
    if (!mConfig) {
        return false;
    }
    initHooks();
    return true;
}

bool Entry::disable() {
    unloadHooks();
    return true;
}

bool Entry::unload() { return true; }

} // namespace FuckEntityPush

LL_REGISTER_MOD(FuckEntityPush::Entry, FuckEntityPush::Entry::getInstance());
