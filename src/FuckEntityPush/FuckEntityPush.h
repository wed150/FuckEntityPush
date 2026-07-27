#pragma once

#include "Config.h"
#include "ll/api/mod/NativeMod.h"

namespace FuckEntityPush {

void initHooks();
void unloadHooks();

class Entry {

public:
    static Entry& getInstance();

    Entry() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    Config& getConfig();

    /// @return True if the mod is loaded successfully.
    static bool load();

    /// @return True if the mod is enabled successfully.
    static bool enable();

    /// @return True if the mod is disabled successfully.
    static bool disable();

    /// @return True if the mod is unloaded successfully.
    static bool unload();

private:
    ll::mod::NativeMod&   mSelf;
    std::optional<Config> mConfig;
};

} // namespace FuckEntityPush
