#include "FuckEntityPush.h"

#include "Config.h"
#include "ll/api/mod/RegisterHelper.h"


namespace FuckEntityPush {

Entry& Entry::getInstance() {
    static Entry instance;
    return instance;
}

Config& Entry::getConfig() { return mConfig.value(); }

bool Entry::load() { return true; }

bool Entry::enable() {
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
