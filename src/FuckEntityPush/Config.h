#pragma once

struct Config {
    int version = 1;
    bool enable              = true;
    bool disableVec0Push     = true;
    int  maxPushTimes        = -1;
    bool unlimitedPlayerPush = false;
};
