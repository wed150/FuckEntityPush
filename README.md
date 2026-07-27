# FuckEntityPush

[![English](https://img.shields.io/badge/English-informational?style=for-the-badge)](README.en.md)
![中文](https://img.shields.io/badge/简体中文-inactive?style=for-the-badge)

是LeviOptimize的实体拥挤减少功能的分支, 由于本人服务器需要而制作.
通过解决大量实体碰撞的问题来提升服务器性能。该插件在LeviLamina框架内运作，通过修改BDS代码以实现显著的性能改进。





## 安装

### 使用Lip

```sh
lip install github.com/wed150/FuckEntityPush
```

### 手动安装

1. 从[发布页面](https://github.com/LiteLDev/LeviOptimize/releases)下载最新版本
2. 解压`FuckEntityPush-windows-x64.zip`文件
3. 将`FuckEntityPush`文件夹复制到BDS安装目录下的`mods`文件夹中

## 配置

首次运行后，FuckEntityPush将在`mod/FuckEntityPush/config/`中生成配置文件，您可以修改这些文件以定制插件的行为

### 配置项

- #### `enable`:

  是否启用插件，默认`true`

- #### `disableVec0Push`:

  当实体碰撞向量为零时阻止实体被挤压，无需显著改变游戏玩法即可提高性能
- #### `maxPushTimes`:

  限制实体每刻被推动的次数，`0`相当于取消实体推动,默认值`-1`表示此限制默认关闭，谨慎调整以避免影响原生特性
- #### `unlimitedPlayerPush`:
 
  不限制与玩家相关的推动，只在`maxPushTimes`启用时生效(不等于`-1`)，默认`false`

>[!Important]
> 
> Q: 如何完全关闭实体推动
> 
> A: `maxPushTimes`设置为0

## 贡献

欢迎通过创建问题或提交PR来提问和贡献

## 许可证

GPL-3.0-or-later 

---

<div style="text-align: center;">© 2026 wed150. Licensed under GPL-3.0-or-later. Forked from [LiteLDev/LeviOptimize](https://github.com/LiteLDev/LeviOptimize) (GPL-3.0-or-later).</div>

