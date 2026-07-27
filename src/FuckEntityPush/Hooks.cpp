#include "FuckEntityPush.h"


#include <expected>

#include "ll/api/memory/Hook.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/util/PushableByEntityUtility.h"
#include "mc/world/actor/Actor.h"
#include "mc/world/level/Level.h"
#include "parallel_hashmap/phmap.h"


namespace FuckEntityPush {

LL_STATIC_HOOK(
    PushableByEntityUtilityPushVec0Opt,
    ll::memory::HookPriority::Normal,
    &PushableByEntityUtility::push,
    void,
    class Actor&      owner,
    class Vec3 const& vec
) {
    if (vec == 0) return;
    origin(owner, vec);
}

static phmap::flat_hash_map<Actor*, int> pushedEntityTimes;
static phmap::flat_hash_map<Actor*, int> emptyMap;

LL_STATIC_HOOK(
    PushableByEntityUtilityPushMaxPushOpt,
    ll::memory::HookPriority::Normal,
    &PushableByEntityUtility::push,
    void,
    class Actor& owner,
    class Actor& other,
    bool         pushSelfOnly
) {
    const auto& config = Entry::getInstance().getConfig();
    if (config.maxPushTimes == 0) return;

    if (config.unlimitedPlayerPush && (owner.isPlayer() || other.isPlayer())) {
        origin(owner, other, pushSelfOnly);
        return;
    }
    // if (++pushedEntityTimes[&owner] > config.maxPushTimes) return;
    auto [it, inserted] = pushedEntityTimes.try_emplace(&owner, 0);
    if (++it->second > config.maxPushTimes) return;
    origin(owner, other, pushSelfOnly);
}


LL_TYPE_INSTANCE_HOOK(TickHook, ll::memory::HookPriority::Normal, Level, &Level::$tick, void) {
    origin();
    pushedEntityTimes.swap(emptyMap);
}


void initHooks() {
    const auto config = Entry::getInstance().getConfig();
    if (config.enable) {
        if (config.disableVec0Push) PushableByEntityUtilityPushVec0Opt::hook();
        if (config.maxPushTimes >= 0) {
            PushableByEntityUtilityPushMaxPushOpt::hook();
            if (config.maxPushTimes != 0) TickHook::hook();
        }
    }
}

void unloadHooks() {
    PushableByEntityUtilityPushVec0Opt::unhook();
    PushableByEntityUtilityPushMaxPushOpt::unhook();
    TickHook::unhook();
}

} // namespace FuckEntityPush
