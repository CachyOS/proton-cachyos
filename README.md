Introduction
------------

**Proton** is a tool for use with the Steam client which allows games which are
exclusive to Windows to run on the Linux operating system. It uses Wine to
facilitate this.

**Proton-CachyOS** is a tool for use with the Steam client and
[umu-launcher][umu-launcher] which builds on Proton introducing experimental
features, third-party tools and more. You can find binary packages for use
with Steam Linux Runtime in this repository's [releases][releases].

**Most users should use Proton provided by the Steam Client itself.** See
[this Steam Community post][steam-play-introduction] for more details. This
custom Proton distributions is provided for users who want to test bleeding-edge
features, community modifications and stores other than Steam.

**The changelog** is available in [CHANGELOG.md][changelog-md].

**Build instructions** are available in [BUILDING.md][building-md].

[steam-play-introduction]: https://steamcommunity.com/games/221410/announcements/detail/1696055855739350561

[umu-launcher]: https://github.com/Open-Wine-Components/umu-launcher

[releases]: https://github.com/CachyOS/proton-cachyos/releases

[changelog-md]: https://github.com/CachyOS/proton-cachyos/blob/cachyos_main/CHANGELOG.md

[building-md]: https://github.com/CachyOS/proton-cachyos/blob/cachyos_main/BUILDING.md


Runtime Config Options
----------------------

Proton can be tuned at runtime to help certain games run. The Steam client sets
some options for known games using the `STEAM_COMPAT_CONFIG` variable.
You can override these options using the environment variables described below.

The best way to set these environment overrides for all games is by renaming
`user_settings.sample.py` to `user_settings.py` and modifying it appropriately.
This file is located in the Proton installation directory in your Steam library
(often `~/.steam/steam/steamapps/common/Proton #.#`).

If you want to change the runtime configuration for a specific game, you can
use the `Set Launch Options` setting in the game's `Properties` dialog in the
Steam client. Set the variable, followed by `%command%`. For example, input
"`PROTON_USE_WINED3D=1 %command%`" to use the OpenGL-based wined3d renderer
instead of the Vulkan-based DXVK renderer.

To enable an option, set the variable to a non-`0` value. To disable an
option, set the variable to `0`. To use Steam's default configuration, do
not specify the variable at all.

All of the below are runtime options. They do not effect permanent changes to
the Wine prefix. Removing the option will revert to the previous behavior.

| Compat config string | Environment Variable                     | Description                                                                                                                                                                                                            |
|:---------------------|:-----------------------------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                      | `PROTON_LOG`                             | Convenience method for dumping a useful debug log to `$PROTON_LOG_DIR/steam-$APPID.log`. Set to `1` to enable default logging, or set to a string to be appended to the default `WINEDEBUG` channels.                  |
|                      | `PROTON_LOG_DIR`                         | Output log files into the directory specified. Defaults to your home directory.                                                                                                                                        |
|                      | `PROTON_WAIT_ATTACH`                     | Wait for a debugger to attach to steam.exe before launching the game process. To attach to the game process at startup, debuggers should be set to follow child processes.                                             |
|                      | `PROTON_CRASH_REPORT_DIR`                | Write crash logs into this directory. Does not clean up old logs, so may eat all your disk space eventually.                                                                                                           |
| `wined3d`            | `PROTON_USE_WINED3D`                     | Use OpenGL-based wined3d instead of Vulkan-based DXVK for d3d11, d3d10, and d3d9.                                                                                                                                      |
| `nod3d11`            | `PROTON_NO_D3D11`                        | Disable `d3d11.dll`, for d3d11 games which can fall back to and run better with d3d9.                                                                                                                                  |
| `nod3d10`            | `PROTON_NO_D3D10`                        | Disable `d3d10.dll` and `dxgi.dll`, for d3d10 games which can fall back to and run better with d3d9.                                                                                                                   |
| `dxvkd3d8`           | `PROTON_DXVK_D3D8`                       | Use DXVK's `d3d8.dll`.                                                                                                                                                                                                 |
| `nofsync`            | `PROTON_NO_FSYNC`                        | Do not use futex-based in-process synchronization primitives. (Automatically disabled on systems with no `FUTEX_WAIT_MULTIPLE` support.)                                                                               |
|                      | `HOST_LC_ALL`                            | Set value to a locale to override all other system locale settings for a game.  This variable should be used instead of `LC_ALL`.                                                                                      |
| `disablenvapi`       | `PROTON_DISABLE_NVAPI`                   | Disable NVIDIA's NVAPI GPU support library.                                                                                                                                                                            |
| `nativevulkanloader` |                                          | Use the Vulkan loader shipped with the game instead of Proton's built-in Vulkan loader. This breaks VR support, but is required by a few games.                                                                        |
| `forcelgadd`         | `PROTON_FORCE_LARGE_ADDRESS_AWARE`       | Force Wine to enable the LARGE_ADDRESS_AWARE flag for all executables. Enabled by default.                                                                                                                             |
| `heapdelayfree`      | `PROTON_HEAP_DELAY_FREE`                 | Delay freeing some memory, to work around application use-after-free bugs.                                                                                                                                             |
| `gamedrive`          | `PROTON_SET_GAME_DRIVE`                  | Create an S: drive which points to the Steam Library which contains the game.                                                                                                                                          |
| `noforcelgadd`       |                                          | Disable forcelgadd. If both this and `forcelgadd` are set, enabled wins.                                                                                                                                               |
| `oldglstr`           | `PROTON_OLD_GL_STRING`                   | Set some driver overrides to limit the length of the GL extension string, for old games that crash on very long extension strings.                                                                                     |
| `vkd3dfl12`          |                                          | Force the Direct3D 12 feature level to 12, regardless of driver support.                                                                                                                                               |
| `vkd3dbindlesstb`    |                                          | Put `force_bindless_texel_buffer` into `VKD3D_CONFIG`.                                                                                                                                                                 |
| `nomfdxgiman`        | `WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER` | Enable hack to work around video issues in some games due to incomplete IMFDXGIDeviceManager support.                                                                                                                  |
| `noopwr`             | `WINE_DISABLE_VULKAN_OPWR`               | Enable hack to disable Vulkan other process window rendering which sometimes causes issues on Wayland due to blit being one frame behind.                                                                              |
| `hidenvgpu`          | `PROTON_HIDE_NVIDIA_GPU`                 | Force Nvidia GPUs to always be reported as AMD GPUs. Some games require this if they depend on Windows-only Nvidia driver functionality. See also DXVK's nvapiHack config, which only affects reporting from Direct3D. |
|                      | `WINE_FULLSCREEN_INTEGER_SCALING`        | Enable integer scaling mode, to give sharp pixels when upscaling.                                                                                                                                                      |
|                      | `WINE_USE_KWIN_HACKS`                    | Enable KDE-specific windowing hacks that may improve experience with KDE older than 6.4 on Wayland and KDE older than 6.6 on X11.                                                                                      |
| `cmdlineappend:`     |                                          | Append the string after the colon as an argument to the game command. May be specified more than once. Escape commas and backslashes with a backslash.                                                                 |
| `xalia` or `noxalia` | `PROTON_USE_XALIA`                       | Enable Xalia, a program that can add a gamepad UI for some keyboard/mouse interfaces, or set to 0 to disable. The default is to enable it dynamically based on window contents.                                        |
| `fnad3d11`           | `FNA3D_FORCE_DRIVER=D3D11`               | Force FNA to use D3D11 for rendering.                                                                                                                                                                                  |
| `seccomp`            | `PROTON_USE_SECCOMP`                     | **Note: Obsoleted in Proton 5.13.** In older versions, enable seccomp-bpf filter to emulate native syscalls, required for some DRM protections to work.                                                                |
| `d9vk`               | `PROTON_USE_D9VK`                        | **Note: Obsoleted in Proton 5.0.** In older versions, use Vulkan-based DXVK instead of OpenGL-based wined3d for d3d9.                                                                                                  |

Proton-CachyOS Config Options
----------------------

| Compat config string | Environment Variable           | Description                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|:---------------------|:-------------------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                      | `PROTON_LOG`                   | In case of videos/audio not playing or being replaced by the [SMPTE color bars](https://en.wikipedia.org/wiki/SMPTE_color_bars), use`"+mfplat,+quartz,+wmvcore,+wmadec,+dmo"` instead of `1`.                                                                                                                                                                                                                                                                                      |
| `dxvksarek`          | `PROTON_DXVK_SAREK`            | Use the [dxvk-sarek](https://github.com/pythonlover02/DXVK-Sarek) fork as DXVK replacement for older GPUs that don't properly support Vulkan 1.3 (supported Vulkan 1.1.x to 1.2.x). It is using the `async` branch, so it **SHOULD NOT** to be used with games using anti-cheat or multiplayer games in general. You have been warned.                                                                                                                                             |
| `dxvklowlatency`     | `PROTON_DXVK_LOWLATENCY`       | Enable the alternative [dxvk-low-latency](https://github.com/netborg-afps/dxvk-low-latency) fork, which enhances the original dxvk with low-latency frame pacing capabilities to improve game responsiveness and input lag. It also improves latency stability over time, usually resulting in a more accurate playback speed of the generated video. Refer to the project's [documentation](https://github.com/netborg-afps/dxvk-low-latency#options) for in-depth configuration. |
| `d7vkddraw`          | `PROTON_D7VK_DDRAW`            | Use `ddraw.dll` from the [D7VK project](https://github.com/WinterSnowfall/d7vk) for DirectX 7-or-lower games.                                                                                                                                                                                                                                                                                                                                                                      |
| `fsr4`               | `PROTON_FSR4_UPGRADE`          | Automatically download `amdxcffx64.dll` and upgrade games with FSR 3.1 to use FSR 4. Version to download can be specified by supplying it as a value, like so `PROTON_FSR4_UPGRADE="4.0.1"`, instead of `1`. Downloads the latest available and known-good version of the required DLL by default.                                                                                                                                                                                 |
| `fsr4hud`            | `PROTON_FSR4_INDICATOR`        | Enable the FSR4 watermark at the top left portion of the screen. This is a shorthand option for setting `FSR_WATERMARK=1` and `FSR_FG_WATERMARK=1`.                                                                                                                                                                                                                                                                                                                                 |
| `mlfg`               | `PROTON_MLFG_UPGRADE`          | Enables the use of MLFG with FSR4 >= `4.0.3`.                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| `dlss`               | `PROTON_DLSS_UPGRADE`          | Automatically download and use newer versions of `nvngx_dlss(d\|g).dll` DLLs. Version to download can be specified by supplying it as a value, like so `PROTON_DLSS_UPGRADE="310.2"`, instead of `1`, to download version `310.2.1.0`. This option also sets `DXVK_NVAPI_DRS_SETTINGS` to use the latest preset. If you provide your own configuration through this environment variable, your configuration will override the defaults.                                           |
| `dlsshud`            | `PROTON_DLSS_INDICATOR`        | Enable the DLSS overlay at the bottom left portion of the screen.                                                                                                                                                                                                                                                                                                                                                                                                                  |
| `xess`               | `PROTON_XESS_UPGRADE`          |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `ffx3`               | `PROTON_FFX3_UPGRADE`          |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `ffx4`               | `PROTON_FFX4_UPGRADE`          |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `nvidialibs`         | `PROTON_NVIDIA_LIBS`           | Enable [alternative implementations of Nvidia libraries](https://github.com/SveSop/nvidia-libs) missing from Proton. Allows things like hardware-accelerated PhysX to function and should be use **only when needed**. This option enables all of `nvcuda`, `nvenc`, `nvml` and `nvoptix`. These are incompatible with `wow64` and thus disabled when `PROTON_USE_WOW64=1` is set.                                                                                                 |
| `nvidialibsno32`     | `PROTON_NVIDIA_LIBS_NO_32BIT`  | Use with the previous option, to enable only the 64bit nvidia libraries. Useful if you are using RTX series 4000 or 5000 GPUs and you had bad performance or crashes when enabling these with 32bit games.                                                                                                                                                                                                                                                                         |
| `nvcuda`             | `PROTON_NVIDIA_NVCUDA`         | Enable alternative `nvcuda.dll` [from nvidia-libs](https://github.com/SveSop/nvcuda) only.                                                                                                                                                                                                                                                                                                                                                                                        |
| `nvenc`              | `PROTON_NVIDIA_NVENC`          | Enable alternative `nvcencodeapi(64).dll` [from nvidia-libs](https://github.com/SveSop/nvenc) only.                                                                                                                                                                                                                                                                                                                                                                               |
| `nvml`               | `PROTON_NVIDIA_NVML`           | Enable alternative `nvml.dll` [from nvidia-libs](https://github.com/Saancreed/wine-nvml) only. This option is enabled by default.                                                                                                                                                                                                                                                                                                                                                 |
| `nvoptix`            | `PROTON_NVIDIA_NVOPTIX`        | Enable alternative `nvoptix.dll` [from nvidia-libs](https://github.com/SveSop/wine-nvoptix) only.                                                                                                                                                                                                                                                                                                                                                                                 |
| `nowmdecoration`     | `PROTON_NO_WM_DECORATION`      | Disable window decorations by the the window manager, use wine's own window decorations.                                                                                                                                                                                                                                                                                                                                                                                           |
| `wayland`            | `PROTON_ENABLE_WAYLAND`        | Enable Wayland support. `winewayland` is experimental and work-in-progress, expect issues. When reporting issues ALWAYS mention if you using this environment variable, and make sure the issue still happens without it. Valve's Protons do not include `winewayland.drv`, they always use `winex11.drv`. For more information refer to [this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#proton-wayland-quirks)                                        |
| `wayland`            | `PROTON_USE_WAYLAND`           | Alias of `PROTON_ENABLE_WAYLAND`                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| `pipewire`           | `PROTON_USE_PIPEWIRE`          | Enable the `winepipewire.drv` audio driver. This audio driver is enabled by default and can be disabled with `PROTON_USE_PIPEWIRE=0`. For more information and further configuration refer to [this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#pipewire-audio-driver)                                                                                                                                                                                   |
|                      | `DXVK_HDR`                     | Enables HDR when set to `DXVK_HDR=1`, optionally combined with `ENABLE_HDR_WSI=1` if required, on Nvidia driver versions older than `595.x.x`.                                                                                                                                                                                                                                                                                                                                     |
|                      | `DXVK_NO_HDR`                  | The opposite of `DXVK_HDR=1`, forcefully disables HDR if it is automatically enabled. **NOTE**: Presently Gnome does **not** support enough color management features to expose HDR automatically.                                                                                                                                                                                                                                                                                 |
| `sdlinput`           | `PROTON_PREFER_SDL`            | Uses SDL input instead of HIDRAW/Steam Input                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| `sdlinput`           | `PROTON_USE_SDL`               | Alias of `PROTON_PREFER_SDL`                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
|                      | `PROTON_NO_STEAMINPUT`         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `localshadercache`   | `PROTON_LOCAL_SHADER_CACHE`    | Enable per-game shader cache even if "Shader Pre-caching" is disabled. Any configuration set by this option can be overriden, i.e. if one of the environment variables is already set, the user-set value will be used. The default configuration is set up to mimic Steam's "Shader Pre-Caching", with shaders being cached under `<steamlibrary>/shadercache/<appid>` for each game.                                                                                             |
| `mediaconv`          | `PROTON_ENABLE_MEDIACONV`      | For debugging purposes, do not use.                                                                                                                                                                                                                                                                                                                                                                                                                                                |
|                      | `PROTON_MEDIA_FORCE_GST`       | Fixes video/audio playback in cutscenes in some cases.                                                                                                                                                                                                                                                                                                                                                                                                                             |
|                      | `PROTON_GST_VIDEO_ORIENTATION` | Change the orientation (rotation) of videos rendered using gstreamer. The accepted values are [the same as gstreamer's `videoflip` plugin](https://gstreamer.freedesktop.org/documentation/videofilter/videoflip.html?gi-language=c#named-constant)                                                                                                                                                                                                                                |
| `vkreflex`           | `DXVK_NVAPI_VKREFLEX`          | Enables [DXVK-NVAPI's Vulkan Reflex layer](https://github.com/jp7677/dxvk-nvapi?tab=readme-ov-file#vulkan-reflex-layer) to support [Reflex in Vulkan](https://docs.nvidia.com/datacenter/tesla/driver-installation-guide/gaming.html#reflex-for-vulkan-steam-play-proton) games. It's meant to enable Reflex in games such as Portal RTX, Path of Exile 1 and 2 and Doom TDA, etc.                                                                                                 |
| `lowlatencylayer`    | `LOW_LATENCY_LAYER`            | Enables [`low_latency_layer`](https://github.com/Korthos-Software/low_latency_layer), for more information and and configuration options refer to the projects README.                                                                                                                                                                                                                                                                                                             |
|                      | `PROTON_USE_OPTISCALER`        | Enables automatic [OptiScaler](https://github.com/optiscaler/OptiScaler) injection. For more information refer to [this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#optiscaler-integration)                                                                                                                                                                                                                                                              |
|                      | `PROTON_DISCORD_BRIDGE`        | Enables [`rpc-bridge`](https://github.com/enderice2/rpc-bridge) to allow games running in Proton to set Discord's Rich Presence.                                                                                                                                                                                                                                                                                                                                                   |

Other Useful Config Options
----------------------

| Compat config string | Environment Variable | Description                                                                                                                                                                                                                                                                                                                                                                                          |
|:---------------------|:---------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                      | `WINE_BLOCK_HOSTS`   | Provides a list of hosts for Wine to not connect to. The list can be either comma (`,`) or semicolon (`;`) separated, i.e `WINE_BLOCK_HOSTS=host1.org,host2.net`. The maximum number of hosts is 16 and the maximum length of each host is 256 characters.                                                                                                                                           |
|                      | `WINEALSA_CHANNELS`  | Allows to select more than two channels with the winealsa driver as well as force disable spatial audio in games. Can be useful with surround setups or when the sounds come out wrong positionally (like dialogue coming out only from the left speaker). Possible values is the number of speakers, such as `2` (to disable spatial audio), such as `4` (2 front, 2 rear), `6` (5.1) or `8` (7.1). |
|                      | `WINEALSA_SPATIAL`   | Properly downmixes spatial with `winealsa` and includes the height channels. Use `1` to enable, `0` to disable (default). Recommended only if there are spatial audio errors with the `WINEALSA_CHANNELS` variable                                                                                                                                                                                   |
|                      | `WINE_AUDIO_DRIVER`  | Comma-separated list of audio drivers for wine to choose from. The default list is `pipewire,pulse,alsa`. For example `WINE_AUDIO_DRIVER=pulse` will use `winepulse.drv` exclusively.                                                                                                                                                                                                                |
|                      | `GST_GL_WINDOW`      |                                                                                                                                                                                                                                                                                                                                                                                                      |


### Proton wayland quirks

If something that uses Electron/CEF (launchers like Battle.net, Ubisoft Connect, EA App, Rockstar Launcher) doesn't
work (displays as white window) after enabling native Wayland support, try adding `--in-process-gpu` to the command
arguments. If you encounter controller issues with `winewayland.drv`, try using `PROTON_USE_SDL=1`, or running Steam
with `-steamos3` which might allow Steam Input to work. For other options relating to `winewayland.drv` refer
to [Proton-EM documentation](https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md)

**NOTE:** The automated wayland hacks that were included in Proton 10 have been removed on purpose pending a proper
implementation. This is the reason previous versions seemed to work but in Proton 11 some launchers display as a white
window.


### Pipewire audio driver
* The driver is enabled by default. To disable it and use `winepulse.drv` set `PROTON_USE_PIPEWIRE=0`.
* You can also use `WINE_AUDIO_DRIVER` to set the list of audio drivers for wine to choose from. The default list
  is `pipewire,pulse,alsa`. For example `WINE_AUDIO_DRIVER=pulse` will use `winepulse.drv` exclusively.
* When reporting issues with `winepipewire.drv` remember to use `PROTON_LOG=warn+pipewire,warn+mmdevapi %command%`
  to create meaningful logs. Make sure to leep the logging level at `warn+` as shown.
  Full tracing (`+pipewire,+mmdevapi`) floods the log and perturbs audio timing enough to cause crackling,
  so only use it for a short capture and remove it for normal play.
* **Lower latency** (system-wide; smaller = lower latency, more CPU; `0` = auto)
    ```
    pw-metadata -n settings 0 clock.force-quantum 256
    ```
  To make it permanent edit `~/.config/pipewire/pipewire.conf.d/99-lowlatency.conf`:
    ```
    context.properties = { default.clock.min-quantum = 256 }
    ```
  Setting `PIPEWIRE_LATENCY` does nothing here, use the quantum above.
* **Choose output device** - games follow your PipeWire default sink. Change it in
  your sound settings, `pavucontrol` (Playback tab), or `wpctl set-default <id>`.
  The game shows up named after itself or as `winepipewire`.
* You can make sure the game uses `winepipewire.drv` either through `pw-top` or by looking at the audio device
  names in the game itself which should include `(Pipewire)` in their name.         



### Optiscaler integration

* Other than `PROTON_USE_OPTISCALER=1` to enable it, you might need to use `PROTON_OPTISCALER_NAME=<name.dll>` to
  control the DLL that should be injected. Three names are supported for `PROTON_OPTISCALER_NAME`, `dxgi.dll`,
  `d3d12.dll` and `dbghelp.dll` and defaults to `dxgi.dll` unless explictly set.
* You can use `PROTON_OPTISCALER_CONFIG` write arbitrary configuration in `OptiScaler.ini`. The config is a semicolon (
  `;`) separated string of individual options. The template for each option is `{section}.{option}={value}`, for example
  `PROTON_OPTISCALER_CONFIG="Upscalers.Dx11Upscaler=fsr31;Upscalers.Dx12Upscaler=dlss"`. To avoid mistakes, only config
  options that already exist in `Optiscaler.ini` can be modified.
* The changes to the config are permanent until OptiScaler is upgraded or downgraded to a different version. To modify a
  setting it has to either be manually edited or altered by applying a different config through the environment
  variable. Be careful, using this will also remove any comments from the `OptiScaler.ini` file. Keep a backup or refer
  to [the repo](https://github.com/optiscaler/OptiScaler/blob/master/OptiScaler.ini) for documentation of the various
  settings.
* When enabled, the `PROTON_<UPSCALER>_UPGRADE` options can be used to dictate the versions of the upscaler DLLs to
  download and use, so `PROTON_FSR4_UPGRADE=4.0.2` will download the FidelityFX DLLs for version `4.0.2`.
* The configuration files are placed with the DLLs in `<prefix>/drive_c/windows/system32/umu/` in case you need to edit
  them. Further configuration options exposed through environment variables are not planned, and likely to not be
  implemented.
* Right now drop-in DLL replacements are not possible, since the files are validated on each startup. If you need more
  fine-grained control than what is offered by the in-game menu, it's probably better to manually set up OptiScaler.
* I consider this work-in-progress, and it will certainly not work with all games. **Do not report issues to OptiScaler
  when using this, always try their own manual installation first (and of course disable this feature when doing so).**


Retired environment variables
----------------------
The following environment variables have been removed or replaced

| **Old** Environment Variable | **New** Environment Variable | Description                                                                                                                                                                                                                                                                                                                                                                        |
|:-----------------------------|:-----------------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| `WINEPULSE_FAST_POLLING`     | N/A                          | Can help eliminate crackling with the default audio driver. Use `1` to enable, `0` to disable (default). Can cause rare crackling in God of War Ragnarok with the power of two quants (e.g. `512`/`768`/`1024`)                                                                                                                                                                    |
| `PROTON_ENABLE_HDR`          | `DXVK_HDR`                   |                                                                                                                                                                                                                                                                                                                                                                                    |
| `PROTON_VKREFLEX`            | `DXVK_NVAPI_VKREFLEX`        | Enables [DXVK-NVAPI's Vulkan Reflex layer](https://github.com/jp7677/dxvk-nvapi?tab=readme-ov-file#vulkan-reflex-layer) to support [Reflex in Vulkan](https://docs.nvidia.com/datacenter/tesla/driver-installation-guide/gaming.html#reflex-for-vulkan-steam-play-proton) games. It's meant to enable Reflex in games such as Portal RTX, Path of Exile 1 and 2 and Doom TDA, etc. |
| `PROTON_MEDIA_USE_GST`       | `PROTON_MEDIA_FORCE_GST`     | Fixes video/audio playback in cutscenes in some cases.                                                                                                                                                                                                                                                                                                                             |
| `PROTON_VKD3D_HEAP`          | N/A                          |                                                                                                                                                                                                                                                                                                                                                                                    |

<!-- Target:  GitHub Flavor Markdown.  To test locally:  pandoc -f markdown_github -t html README.md  -->
