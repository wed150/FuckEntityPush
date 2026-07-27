# FuckEntityPush

[![简体中文](https://img.shields.io/badge/简体中文-inactive?style=for-the-badge)](README.md)
![English](https://img.shields.io/badge/English-informational?style=for-the-badge)

A fork of LeviOptimize's entity crowding reduction feature, created to meet the needs of my own server.
It improves server performance by resolving issues caused by massive entity collisions. This plugin operates within the LeviLamina framework and achieves significant performance gains by patching BDS code.

## Installation

### Using Lip

```sh
lip install github.com/wed150/FuckEntityPush
```

### Manual Installation

1. Download the latest release from the [Releases page](https://github.com/wed150/FuckEntityPush/releases)
2. Extract the `FuckEntityPush-windows-x64.zip` archive
3. Copy the `FuckEntityPush` folder into the `mods` directory of your BDS installation

## Configuration

On first run, FuckEntityPush will generate configuration files in `mod/FuckEntityPush/config/`. You can modify these files to customize the plugin's behavior.

### Configuration Options

- #### **`enable`**:
  Whether to enable the plugin. Default: `true`

- #### **`disableVec0Push`**:
  Prevents entities from being pushed when the collision vector is zero. Improves performance without noticeably altering gameplay.

- #### **`maxPushTimes`**:
  Limits how many times an entity can be pushed per tick. Setting to `0` effectively disables entity pushing. Default: `-1` (disabled). Adjust with caution to avoid breaking vanilla behavior.

- #### **`unlimitedPlayerPush`**:
  Does not limit pushes involving players. Only takes effect when `maxPushTimes` is enabled (not `-1`). Default: `false`

> [!Important]
>
> **Q: How do I completely disable entity pushing?**
>
> **A:** Set `maxPushTimes` to `0`.

## Contributing

Questions and contributions are welcome—feel free to open an issue or submit a pull request.

## License

GPL-3.0-or-later

---

<div style="text-align: center;">© 2026 wed150. Licensed under GPL-3.0-or-later. Forked from [LiteLDev/LeviOptimize](https://github.com/LiteLDev/LeviOptimize) (GPL-3.0-or-later).</div>

