### Version 11.0-20261005
* Proton (SLR and Native)
   - Updated to Proton Experimental [`11.0-20261001`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20261001)
   - The wine submodule has been rebased on top of wine from Proton-EM, instead of picking individual series of patches. This not only makes rebasing considerably easier. Our wine retains the various extra patches it previously had, which are applied on of the new base. Thanks to @BananaWorks07 and @NelloKudo for their combined efforts to upstream stuff which we can later import back into our projects.
   - Updated `winepipewire.drv` to fix various issues that have been reported since it was included. Thanks to @M0n7y5. PR: https://github.com/CachyOS/wine-cachyos/pull/27
   - Fixed some issues with Brazilian ABNT keys in `winewayland.drv`. Thanks to @bk304. PRs: https://github.com/CachyOS/wine-cachyos/pull/26, https://github.com/BananaWorks07/wine-valve/pull/2
   - Updated `d7vk` to the latest [`v2.3`](https://github.com/WinterSnowfall/d7vk/releases/tag/v2.3) release
   - Updated `dxvk-sarek` to [`v1.13.0-36-gcc9412c9`](https://github.com/pythonlover02/dxvk-sarek/commit/cc9412c9a46a522691ae45791a62bf63887c3d9f)
   - Updated `dxvk-low-latency` to [`low-latency-framepacing-3.1.1-2`](https://github.com/netborg-afps/dxvk-low-latency/commit/d533db09df35453ed1baa1b0c7d86de2b67bf504)
   - Updated `vkd3d-low-latency` to [`low-latency-3.0.1-2`](https://github.com/netborg-afps/vkd3d-low-latency/commit/f4e0518cdd35fee0629e25367422bcbc17cbc122)
   _ Updated `nvidia-libs` to their respective latest versions
   - Updated `protonfixes` to the version [`1.0.15-1853-gf842871`](https://github.com/Open-Wine-Components/umu-protonfixes/commit/f84287168e3ec4107131893c63cae76f66ea5011) and included a patch to hide wine version from Witcher 3
   - Fixed videos missing in Witch on the Holy Night. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/264
   - Fixed videos missing in GTA San Andreas. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/246
   - Fixed some cutscenes missing in Wuthering Waves after the 3.7 update. Thanks to @NelloKudo. Issue: https://bugs.winehq.org/show_bug.cgi?id=60408
   - Imported `icuuc.dll` and `icuin.dll` patches from upstream Wine which will prevent the Albion Online Launcher from crashing. 
   - Proton-CachyOS will now load `user_settings.py` from the target compatdata directory as well the proton installation directory.
* Proton (SLR only)
   - None
* Proton (Native only)
   - None
* Wine (Standalone)
   - None

Brought to you by The Berries, [🍌](https://github.com/BananaWorks07) [🍈](https://github.com/NelloKudo) [🍋](https://github.com/loathingKernel), and their friends.

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency
> * For `vkd3d-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/vkd3d-low-latency?tab=readme-ov-file#vkd3d-low-latency

---

### Version 11.0-20260703
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-11.0-20260702-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-11.0-20260702-slr)
   - Included @netborg-afps's [`vkd3d-low-latency`](https://github.com/netborg-afps/vkd3d-low-latency) as an option. It can be enabled with `PROTON_VKD3D_LOWLATENCY=1`. It is **very important** to read and understand the [current status and limitations](https://github.com/netborg-afps/vkd3d-low-latency#status--limitations). Thanks to @netborg-afps
      * `vkd3d-low-latency` features built-in, hardware-agnostic low-latency frame pacing for DX12. It natively implements the NVIDIA Reflex API within the translation layer (bypassing the conversion into `VK_NV_low_latency2`) and also allows for advanced frame pacing via Waitable DXGI Swapchains to significantly reduce input lag.
      * AMD users should also take a look in [the dedicated discussion](https://github.com/netborg-afps/vkd3d-low-latency/discussions/3)
   - Removed the default configuration for `DXVK_HUD` which enabled the `compiler` item. Because the `DXVK_HUD` configuration takes precedence over configuration coming from `dxvk.conf`, using `DXVK_HUD` would override perfectly working setups which used `dxvk.conf` as a way to do per-game configuration.
   - Updated `d7vk`, `dxvk-sarek`, `low_latency_layer` and `nvidia-libs` submodules
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency
> * For `vkd3d-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/vkd3d-low-latency?tab=readme-ov-file#vkd3d-low-latency

---

### Version 11.0-20260702
* Proton (SLR and Native)
   - Updated to Proton Experimental [`11.0-20260701b`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260701b)
   - Added `winepipewire.drv` driver for Wine to directly use Pipewire instead of using `winepulse.drv` and going through pipewire-pulse. Thanks to @M0n7y5.
      * The driver is enabled by default. To disable it and use `winepulse.drv` set `PROTON_USE_PIPEWIRE=0`.
      * You can also use `WINE_AUDIO_DRIVER` to set the list of drivers for wine to choose from. The default list is `pipewire,pulse,alsa`. For example `WINE_AUDIO_DRIVER=pulse` will use `winepulse.drv` exclusively.
      * When reporting issues with `winepipewire.drv` remember to use `PROTON_LOG=warn+pipewire,warn+mmdevapi %command%` for create meaningful logs.
      * You can make sure the game uses `winepipewire.drv` either through `pw-top` or by looking at the audio device names in the game itself which should include `(Pipewire)` in their name.         
   - Imported `amdxc64` changes from Proton-EM to enable FSR4 `4.1.1` on all supported hardware. Thanks to @Etaash-Mathamsetty.
   - Due to the updates regarding FSR4 and the update to version `4.1.1` of `amdxcffx64.dll` the following things have been adjusted accordingly.
      * The `amdxcffx64.dll` driver dll is copied automatically, there is no need to use `PROTON_FSR4_UPGRADE` any more, although the environment variable remains to request a specific version of the dll ( restricted to `4.0.0` and `4.1.1` only right now ).
      * It's worth noting here that when using the OptiScaler integration, `PROTON_FSR4_UPGRADE` will accept more versions than just `4.0.0` and `4.1.1` and it will control the version of the respective FidelityFX SDK dlls.
      * It is not possible anymore to manually provide different `amdxcffx64.dll` dll versions through the protonfixes cache. It was ugly and confusing anyways. I am glad it's gone.
      * Since the dll is always present the following shorter environment variables will also work.
         | Variable       | Description  |
         | :------------- | :----------- |
         | `FSR4_UPGRADE` | Upgrade FSR3/4 to newer FSR4 (FP8 or I8) using AMD's FSR 4.1.1 amdxcffx64.dll taken from Proton Experimental. This option is not needed on RDNA2-4 discrete GPUs. |
         | `MLFG_UPGRADE` | Enables FSR4 MLFG upgrade to use redstone frame generation. Can be used in tandom with FSR4-I8 on RDNA3 using `DXIL_SPIRV_CONFIG=wmma_rdna3_workaround`.          |
      * Removed `PROTON_FSR4_RDNA3_UPGRADE` as setting `DXIL_SPIRV_CONFIG=wmma_rdna3_workaround` is not required any more in most cases, with the exception of enabling MLFG on RDNA3 (see table above).
      * Removed `PROTON_FSR3_UPGRADE`, it has been renamed to `PROTON_FFX3_UPGRADE`. You do not need to ever use this under normal circumstances.
      * To make it a bit confusing again, the versions controlled through `PROTON_FFX4_UPGRADE` can also be controlled through `PROTON_FSR4_UPGRADE` when OptiScaler is enabled, to remain somewhat compatible with existing configurations.
      * I am still considering how to make all this a bit more streamlined and consistent, so expect changes in this area in the future.
   - Added the DualSense 5 patches that were skipped previously due to the rebase to Proton 11.0. Thanks to @xzn.
   - Added some stubs to `dnsapi` which should allow iRacing to run. The anti-cheat blocks the game from fully working. Thanks to @DanFraserUK. MRs: https://github.com/CachyOS/wine-cachyos/pull/18 https://gitlab.winehq.org/wine/wine/-/merge_requests/11208
   - Fixed **Surviving Mars** crashing after loading into the start menu along with some other audio-related issues. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/233 https://github.com/CachyOS/proton-cachyos/issues/236
   - Fixed compile-time configuration for GStreamer, specifically enabled `glib-checks` again, as disabling them caused some issues with media playback since Wine depends on the APIs they provide for fault checking. Thansk to @NelloKudo.
   - Updated `d7vk` to version [`v1.12`](https://github.com/WinterSnowfall/d7vk/releases/tag/v1.12).
   - Improved the Vulkan version detection and the underlying API to also check for driver versions and extensions in the future. Thanks to @CommandMC.
   - Added `PROTON_ADD_CONFIG` environment variable to supply configuration through compatibility configs instead of environment variables. It accepts a comma-separated list of compat configs. If you are wondering what these are, they are the first column in the tables of environment variables in the documentation.
   - Enabled the `compiler` item in `DXVK_HUD` by default. Since there are too many invalid reports due to shader compilation from new users, this should provide a visual feedback aid of what is going on.
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260701b

---

### Version 11.0-20260602
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-11.0-20260601-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-11.0-20260601-slr)
   - Imported some `winewayland.drv` fixes from Proton-EM for color management and mouse pointer handling. Thanks to @Etaash-mathamsetty. Issue: https://github.com/CachyOS/proton-cachyos/issues/225
   - Removed `winex11-Fixed-scancodes` patch-set which was applied in the previous version as it caused a few issues with keyboard keys not working and fixing it requires `winecfg`. Issue: https://github.com/CachyOS/proton-cachyos/issues/223
   - Reverted the patch that allowed executables to be dynamically relocated too. It was included to fix some FFXIV modding tools but it broke the NIKKE installer and caused peformance issues with modded Fallout 4. Issue: https://github.com/CachyOS/proton-cachyos/issues/227
   - Updated Vulkan detection to fallback to `dxvk-sarek` for GPUs that advertise **Vulkan 1.3** but do not support `descriptorIndexing`, for example `Intel HD Graphics 5500 (BDW GT2)`. Thanks to @CommandMC
   - Updated `protonfixes` and added a patch to fix https://github.com/CachyOS/proton-cachyos/issues/219
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260529

---

### Version 10.0-sunset
* Proton (SLR and Native)
   - The last Proton-CachyOS 10.0 release based on [`cachyos-10.0-20260425-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260425-slr)
   - This release closes the Proton-CachyOS 10.0 development cycle. It's retrofitted with some improvements and components from the current Proton 11.0.
      * Updated `dxvk`, `dxvk-nvapi` and `vkd3d-proton` to recent development versions
      * Included `low_latency_layer` and `vkbasalt`
      * Updated `dxvk-sarek` and `d7vk`
      * Backported Vulkan version detection for automatic fallback to `dxvk-sarek`
      * Backported Optiscaler integration and defaulting to Windows 11
      * Backported the updates for `umu-protonfixes` to reduce the size of the prefixes and using `zenity-rs`
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 11.0-20260601
* Proton (SLR and Native)
   - Updated to Proton Experimental [`11.0-20260529`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260529)
   - Imported a lot of `winewayland.drv` improvements from Proton-EM. Thanks to @Etaash-mathamsetty
      * Implement xdg-popup for unmanaged windows with an owner.
      * Fixed race condition with first frame of server side decorations.
      * Implemented client surface reparenting for unmanaged window role transition.
      * Fixed winewayland being broken on wow64 due to a regression. Issues: https://github.com/CachyOS/proton-cachyos/issues/200, https://github.com/CachyOS/proton-cachyos/issues/208
      * Fixed key release with focus loss with keyboard hooks.
      * Fixed ensure window contents and NtUserExposeWindowSurface.
      * Fixed some cases of division by zero.
   - Enabled automatic HDR detection/enablement. In case you need to disable it for any reason, you can set `DXVK_NO_HDR=1`. Thanks to @Etaash-mathamsetty
     **NOTE**: Presently Gnome does **not** support enough color management features to expose HDR automatically.
   - Fixed an issue with videos in **Mega Man Legacy Collection 2** that would cause the game to hang. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/211
   - Fixed an issue with videos in **The Legend of Heroes - Trails in the Sky FC** that caused them to be upside-down. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/199
   - Fixed an issue with videos in **Unravel** and **Unravel Two** that caused the games to crash. Thanks to @NelloKudo. Issue: https://github.com/CachyOS/proton-cachyos/issues/161
   - Fixed an issue that would cause some games to crash or be unable to connect to game servers. Thanks to @GenkaiToppa for finding the offending change. Issues: https://github.com/CachyOS/proton-cachyos/issues/207, https://github.com/CachyOS/proton-cachyos/issues/204, https://github.com/CachyOS/proton-cachyos/issues/201
   - Added Vulkan version detection to automatically use DXVK-Sarek if the primary GPU does **NOT** support **Vulkan 1.3**. Presently the detection is based solely on Vulkan version, which can be wrong in cases where the driver in use only misses certain extensions or features. If for any reason the automatic detection is wrong, you can still force-enable it using `PROTON_DXVK_SAREK=1`, or if you want to disable DXVK-Sarek, you can do so with `PROTON_DXVK_SAREK=0`. Thanks to @CommandMC
   - Changed `PROTON_USE_OPTISCALER` to also download DLSS dlls by default in order to enable DLSS inputs for FSR4. Issue: https://github.com/CachyOS/proton-cachyos/issues/214
   - Added `PROTON_OPTISCALER_CONFIG` to write arbitrary configuration in `OptiScaler.ini` when using `PROTON_USE_OPTISCALER`.
      * The config is a semicolon (`;`) separated string of individual options. The template for each option is `{section}.{option}={value}`, for example `PROTON_OPTISCALER_CONFIG="Upscalers.Dx11Upscaler=fsr31;Upscalers.Dx12Upscaler=dlss"`. To avoid mistakes, only config options that already exist in `Optiscaler.ini` can be modified.
      * The changes to the config are permanent until OptiScaler is upgraded or downgraded to a different version. To modify a setting it has to either be manually edited or altered by applying a different config through the environment variable.
      * Be careful, using this will also remove any comments from the `OptiScaler.ini` file. Keep a backup or refer to [the repo](https://github.com/optiscaler/OptiScaler/blob/master/OptiScaler.ini) for documentation of the various settings.
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260529

---

### Version 11.0-20260521
Well, I guess a lot of things have been happening so another minor update release is in order. Three releases in three days is a bit of a meme, I am right there with you, be sure of that. As you may very well know the **descriptor heap** has been merged into `vkd3d-proton`, so I thought I might aswell do another release to update `vkd3d-proton` and clean some stuff up.

* Proton (SLR and Native)
   - Minor update release based on [`cachyos-11.0-20260520-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-11.0-20260520-slr)
   - Updated `vkd3d-proton` to the latest version. This includes the **descriptor heap** branch now, meaning that only `VKD3D_CONFIG=descriptor_heap` is required to enable it. As a result `PROTON_VKD3D_HEAP` has been removed, only the `VKD3D_CONFIG` configuration is needed to enable **descriptor heap**.
   - The alternative `vkd3d-proton` submodule, which was housing the `descriptor-heap-rebase` branch, has also been removed. It might come back in the future to host other features.
   - Fixed a hang that happened during game startup on **Gnome / Mutter** when using `winewayland.drv`. Thanks to @Etaash-mathamsetty
   - Fixed an issue that would cause games to freeze after switching windows when using `winewayland.drv`. Thanks to @Etaash-mathamsetty
   - Implemented brazil ABNT keyboard layout for `winewayland.drv`. Thanks to @Etaash-mathamsetty
   - Improved media playback for **Darksiders Warmastered Edition**  to render the videos and no longer crash the game. There are still some issues that we are looking into. If you running the game from a store other than Steam, for example EGS or GOG, you will **need** to provide `umu-launcher` with the gameid `GAMEID=umu-462780`. Thanks to @NelloKudo
   - Fixed slow media playback in **Persona 5 Strikers**. Thanks to @NelloKudo
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260518b

---

### Version 11.0-20260520
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-11.0-20260519-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-11.0-20260519-slr)
   - Fixed an issue with defaulting to Windows 11 in Wine, which made the version not being detected correctly and might have caused `dotnet48` to fail during installation.
   - If you are using custom local protonfixes which are installing  any `dotnet*` version, you will also need to update them according to https://github.com/Open-Wine-Components/umu-protonfixes/pull/557. You can also apply the `PROTON_DLL_COPY="*"` (notice the syntax, it's important to quote the value) environment variable if you are installing through the command line. This will considerably increase the size of the prefix.
   - Fixed an issue with `winewayland.drv` which caused some games to not show their window, https://github.com/CachyOS/proton-cachyos/issues/181. Thanks to @Etaash-mathamsetty
   - Updated the alternative `vkd3d-proton` submodule to track `descriptor-heap-rebase` again instead of `forza-workarounds`.
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260518b

---

### Version 11.0-20260519
* Proton (SLR and Native)
   - Updated to Proton Experimental Bleeding Edge [`11.0-20260518b`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260518b)
   - Imported a number of fixes and updates from Proton-EM for `winewayland.drv`. Thanks to @Etaash-mathamsetty
      * Fixed some issues with color management. Thanks to @kode54 for identifying the issues and providing the basis for the fixes https://github.com/CachyOS/wine-cachyos/pull/6, https://github.com/CachyOS/wine-cachyos/pull/8.
      * Fixed a bug where mouse pointer wouldn't warp when the pointer lock was released.
      * Fixed some cases where the winewayland event dispatcher thread would get suspended.
      * Improved ensure contents implementation for opaque surfaces.
   - Improved video playback patches which should allow more games, especially visual novels, to play their media without issues. Games which previously required `PROTON_MEDIA_USE_GST=1`, should work out of the box. Thanks to @NelloKudo
   - Renamed `PROTON_MEDIA_USE_GST` to `PROTON_MEDIA_FORCE_GST` to disable protofixes that used the former to workaround media playback issues. We are cautiously confident that many things will work now out-of-the-box. Still the configuration options remains through the renamed environment variable in case it is still needed for anything or debugging.
   - Removed the extraneous `PROTON_VKREFLEX` environment variable which enabled dxvk-nvapi's Reflex layer. Exposing the layer, as well as enabling it, is now controlled by the original upstream environment variable `DXVK_NVAPI_VKREFLEX=1`.
   - Included [`low_latency_layer`](https://github.com/Korthos-Software/low_latency_layer) as an optional layer. It can be enabled using `LOW_LATENCY_LAYER=1`. This only enables the layer, for further configuration options refer to the project's documentation.
   - Included [`rpc-bridge`](https://github.com/enderice2/rpc-bridge) with Proton to allow games to set Discord's Rich Presence. The service does not run by default and can be enabled using `PROTON_DISCORD_BRIDGE=1`.
   - Fixed the OptiScaler injection method in Wine to work in more games. Due to the way it works, it might hook overlays instead of the game. If that stops OptiScaler from working, you can block it by editing the config and adding the overlay process in the [`ProcessExclusionList`](https://github.com/optiscaler/OptiScaler/blob/master/OptiScaler.ini#L1359). Let us know by making an issue so we can exclude more overlay processes in the future.
   - Updated `protonfixes` to [stop "unsymlinking"](https://github.com/Open-Wine-Components/umu-protonfixes/pull/557) the whole prefix unconditionally. Reduces the size of the prefix and should improve Proton warmup time.
   - If you are using custom local protonfixes which are installing `dotnet` you will also need to update them according to https://github.com/Open-Wine-Components/umu-protonfixes/pull/557. You can also apply the `PROTON_DLL_COPY="*"` (notice the syntax, it's important to quote the value) environment variable if you are installing through the command line.
   - Updated Wine to default to Windows 11
* Proton (SLR specific)
   - None
* Proton (Native specific)
   - None
* Wine (Standalone)
   - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260518b

---

### Version 11.0-20260506
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`11.0-20260506`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260506)
   - Imported a number of fixes and updates from Proton-EM for `winewayland.drv`.
     * Prefer `ext_data_control_manager_v1` over `zwlr_data_control_manager_v1` when present. Thanks to @Etaash-mathamsetty
     * Implemented `VK_COLORSPACE_HDR10_ST2084_EXT` using `windows_bt2100` image description when **version 3** of the `wp_color_manager_v1` protocol is supported (no compositor supports it yet). Thanks to @Etaash-mathamsetty
     * Fixed crashes when the Wayland output image description changes. Thanks to @Etaash-mathamsetty
     * Simplified client surface caching and made it handle more cases. Thanks to @Etaash-mathamsetty
     * Fixed mouse pointer moving abruptly after entering a window when using `winewayland.drv` (https://github.com/CachyOS/proton-cachyos/issues/153). Thanks to @Etaash-mathamsetty
     * Fixed an issue that "upgraded" FSR3.1 to FSR4 on RDNA3 GPUs automatically even without using the intended environemnt variables. Thanks to @Etaash-mathamsetty
   - Removed `PROTON_ENABLE_HDR` as an option. It doesn't make much sense to have it any more, as it also required `ENABLE_HDR_WSI=0` in certain cases. If it is required, you can use `DXVK_HDR=1` instead, optionally with `ENABLE_HDR_WSI=1` on Nvidia driver versions older than `595.x.x`.
   - Fixed more than a few media playback issues.
     * Fixed an issue where some H264 videos would fail to play (e.g. Stella Sora). Thanks to @NelloKudo
     * Fixed an issue where some videos would fail to start on winedmo due to flawed Seek() implementation (e.g. Danganronpa V3). Thanks to @NelloKudo
     * Fixed a crash in faudio and improved WMA videos playback, DMC1 videos should now play fine on winedmo. Thanks to @NelloKudo
     * Fixed intro video not playing in Guilty Gear XX Accent Core Plus R. Thanks to @NelloKudo
   - Fixed semi-transparent webviews in Wuthering Waves. Thanks to @NelloKudo
   - Thanks to @Vyrolian's efforts, improvements have been made in `winepulse.drv` in Valve's Proton, and as a result their older more hacky patch for `winepulse.drv` has been removed. The multi-channel audio patches for `winealsa.drv` are still included.
   - Imported the changes from https://gitlab.winehq.org/wine/wine/-/merge_requests/10829 which tries to make collisions on the futex queues much less likely.
   - Imported the changes from https://gitlab.winehq.org/wine/wine/-/merge_requests/10871 to respect runtime font smoothing settings.
   - Improved `WINE_BLOCK_HOSTS` to block second-level domains too. `WINE_BLOCK_HOSTS=test.org` will block all of `this.test.org`, `other.test.org`. Word of caution, the domain name matching is very naive, so `WINE_BLOCK_HOSTS=org` will block any `.org` TLD.
   - Added basic integration of [OptiScaler](https://github.com/optiscaler/OptiScaler) into `umu-protonfixes` and Proton-CachyOS, see below.
     * Presently it is controlled by two environment variables, `PROTON_USE_OPTISCALER=1` to enable it, and `PROTON_OPTISCALER_NAME=<name.dll>` to control the DLL that should be injected. Three names are supported for `PROTON_OPTISCALER_NAME`, `dxgi.dll`, `d3d12.dll` and `dbghelp.dll` and defaults to `dxgi.dll` unless explictly set.
     * When enabled, the `PROTON_<UPSCALER>_UPGRADE` options can be used to dictate the versions of the upscaler DLLs to download and use, so `PROTON_FSR4_RDNA3_UPGRADE=4.0.2` will download the FidelityFX DLLs for version `4.0.2`. `PROTON_FSR4_RDNA3_UPGRADE=1` still defaults to `4.0.0` and `PROTON_FSR4_UPGRADE=1` defaults to `4.1.0`. You will need either of these to enable FSR4 upscaling presently.
     * The configuration files are placed with the DLLs in `<prefix>/drive_c/windows/system32/umu/` in case you need to edit them. Further configuration options exposed through environment variables are not planned, and likely to not be implemented.
     * Right now drop-in DLL replacements are not possible, since the files are validated on each startup. If you need more fine-grained control than what is offered by the in-game menu, it's probably better to manually set up OptiScaler.
     * I consider this work-in-progress, and it will certainly not work with all games. **Do not report issues to OptiScaler when using this, always try their own manual installation first (and of course disable this feature when doing so).**
     * Thanks to @FakeMichau from the OptiScaler dev team for making this kind of integration possible by identifying and resolving various issues, and @mrlukyxd and @noel-personal for their input and testing while I was implementing it.
   - Updated `d7vk` submodule to [`v1.9`](https://github.com/WinterSnowfall/d7vk/releases/tag/v1.9).
   - Updated `dxvk-sarek` submodule to [`01e9165a`](https://github.com/pythonlover02/DXVK-Sarek/commit/01e9165aebf95957084bea0efe1a7e64499816ec) to include the back-ported `d7vk` updates.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - Converted it back into a multilib package until it's no longer possible for us to build it as such.
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260506

---

### Version 11.0-20260429
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-10.0-20260428-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260428-slr)
   - Added [`zenity-rs`](https://github.com/QaidVoid/zenity-rs) to `umu-protonfixes` as a replacement for `zenity`. SteamRT4 removed `zenity` from the runtime, and that made Winetricks GUI not function. Also fixed Winetricks GUI not working when enabling Wayland in Proton.
   - Imported a couple of updates from Bleeding Edge to fix EAC and Assassin's Creed Shadows (unrelated to each other).
   - Updated [`dxvk`](https://github.com/doitsujin/dxvk/commit/d1b0151cb40288de31d5af4a2e84173c3889afa2), [`dxvk-nvapi`](https://github.com/jp7677/dxvk-nvapi/commit/42ed4947825ff0f4f5f64fe11ebfbb0fc6cb4a3e) and [`vkd3d-proton`](https://github.com/HansKristian-Work/vkd3d-proton/commit/497357c0f03796d1a87696937c8b503106fdca6a)
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260428

---

### Version 11.0-20260428
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`11.0-20260428`](https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260428)
   - First of I would like to thank @Etaash-mathamsetty of [Proton-EM](https://github.com/Etaash-mathamsetty/Proton) and @NelloKudo of [DWProton](https://dawn.wine/dawn-winery/dwproton) for their immense contribution to the project in general and for helping with the rebase on top of Proton 11 in particular.
   - The `PROTON_USE_NTSYNC` environment variable and related configuration has been removed. This is the default now even in Valve's Proton 11, nevertheless `ntsync` can still be disabled by using `PROTON_NO_NTSYNC` provided by Proton 11.
   - Imported `winewayland.drv` updates from Proton-EM 11. One important difference is that Proton-CachyOS doesn't enable HDR by default, you still need `PROTON_ENABLE_HDR=1` for it. The automatic enablement depends on Nvidia `595` drivers, and I didn't want to enforce that requirement.
   - Proton 11 is using SteamRT4, which is missing a few of the libraries that were present in SteamRT3. This led us to disable a few media plugins in `gstreamer` and `ffmpeg`. If you notice lacking media in games when using Proton-CachyOS 11 compared to Proton-CachyOS 10, we would like to know.
   - Almost all of the `wine-staging` patches from Proton-CachyOS 10 have been removed. Only a handful have been added for things that we were certain they were required. We want to keep them at a minimum and add them selectively if they are required to fix an issue.
   - The DualSense patches have been removed, pending a rebase onto Proton 11. If they are still needed, they will be added back in a later version.
   - Removed the Asseto Corsa patch, as the game's HUD seems to work fine using **CSP 0.3** and I did not like what the patch was doing to fix the issue. We also fixed an issue with `PROTON_GST_VIDEO_ORIENTATION` messing up audio playback.
   - The `x86_64_v4` package has been removed. I felt like it wasn't offering anything substantial presently and I needed to free up jobs in the workflows for other builds. You can use either the `x86_64_v3` or `x86_64` instead.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - The native Arch package is going to be pure wow64 from now on. Arch has been removing `lib32-*` packages in lately and I don't want to deal with build failures. Using the Steam Linux Runtime (`-slr`) package has been our recommendation for a long time now, for maximum compatibility.
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-11.0-20260428

---

### Version 10.0-20260425
* Proton (SLR and Native)
   - Final release for the Proton 10 branch based on [`10.0-20260407`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407)
required updates.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260424
* Proton (SLR and Native)
   - Update release based on [`cachyos-10.0-20260420-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260420-slr)
   - Backported the required `wine` and `vkd3d-proton` updates from Proton Experimental Bleeding Edge to fix **Crimson Desert**. Do not use `PROTON_VKD3D_HEAP=1` with the game, the alternative `vkd3d-proton` doesn't have any of the required updates.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260420
* Proton (SLR and Native)
   - Update release based on [`cachyos-10.0-20260410-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260410-slr)
   - Updated `vkd3d-proton`, and the alternative one using the `descriptor-heap-rebase` branch to [`e72c0753`](https://github.com/HansKristian-Work/vkd3d-proton/commit/e72c0753) and [`2889f1c8`](https://github.com/HansKristian-Work/vkd3d-proton/commit/2889f1c8) respectively, *for blazing fast performance on Nvidia (not really, but it does fix a recent [performance issue](https://github.com/HansKristian-Work/vkd3d-proton/issues/2950))*
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260410
* Proton (SLR and Native)
   - Update release based on [`cachyos-10.0-20260409-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260409-slr)
   - Updated the alternative `vkd3d-proton` to the rebased [descriptor heap branch](https://github.com/HansKristian-Work/vkd3d-proton/pull/2943). To enable it you will have to set `VKD3D_CONFIG=descriptor_heap` manually in conjuction with `PROTON_VKD3D_HEAP=1`. The reason is to allow testing of both the legacy and the new code paths with this rebase.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260409
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-10.0-20260408-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260408-slr)
   - Updated `winewayland.drv` patches to fix an [issue](https://github.com/CachyOS/proton-cachyos/issues/131) with Asseto Corsa. Thanks to @Etaash-Mathamsetty.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260408
* Proton (SLR and Native)
   - Bugfix release based on [`cachyos-10.0-20260407-slr`](https://github.com/CachyOS/proton-cachyos/releases/tag/cachyos-10.0-20260407-slr)
   - Fixed `PROTON_DLSS_UPGRADE`, `PROTON_FSR3_UPGRADE` and `PROTON_XESS_UPGRADE` not applying the upgrade properly.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260407
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`10.0-20260407`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407)
   - Added a patch to allow Denuvo to work on Android. Thanks to @pipetto-crypto, @NelloKudo and @klark231.
   - Updated `winewayland.drv` with latest changes from Proton-EM. Previously problematic Vulkan games, such as Doom Eternal, should work properly now. Other fixed issues include window decorations for some CEF applications and window minimize and restore. Thanks to @Etaash-Mathamsetty.
   - Updated `dxvk-low-latency` to the current [low-latency-framepacing-2.7.1-3-521](https://github.com/netborg-afps/dxvk-low-latency/releases/tag/low-latency-framepacing-2.7.1-3-521) release.
   - Updated `d7vk` to [v1.7](https://github.com/WinterSnowfall/d7vk/releases/tag/v1.7)
   - Updated `dxvk-sarek` to [fcafb96](https://github.com/pythonlover02/DXVK-Sarek/commit/fcafb96). This update includes a backported version of `d7vk`, to use it combine the `PROTON_DXVK_SAREK=1` and `PROTON_D7VK_DDRAW=1` options.
   - Split `nvidia-libs/nvcuda` and `nvidia-libs/nvenc` modules to separate sources for 64bit and 32bit libraries and updated the 64bit modules. This was necessary because newer versions of SveSop's nvcuda and nvenc removed 32bit support, see [here](https://github.com/SveSop/nvidia-libs/issues/42) for more information
   - Added `PROTON_USE_WAYLAND` and `PROTON_USE_SDL` aliases for `PROTON_ENABLE_WAYLAND` and `PROTON_PREFER_SDL` respectively.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - `wine-cachyos` packages on CachyOS repos will be built as `wow64` due to a lot of multilib dependencies being removed from the Arch repos.

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.
>
> The `x86_64_v4` package is largely untested and experimental. It may exhibit issues or completely refuse to work.
> Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260407

---

### Version 10.0-20260330
* Proton (SLR and Native)
   - Minor updated release based on the previous [`10.0-20260324`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260324)
   - Backported syscall-related commits from upstream Wine to fix crashes in Where Winds Meet and Ubisoft Connect. Due to the nature of these changes, consider this release as potentially unstable. Thanks to @MarshNello and @Etaash-Mathamsetty for providing a large number of these changes and testing.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.
> 
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260324

---

### Version 10.0-20260324
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`10.0-20260324`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260324).
   - Updated [`vkd3d-proton`](https://github.com/HansKristian-Work/vkd3d-proton/commit/e808096d5) to bleeding-edge.
   - Updated `d7vk` to [v1.6](https://github.com/WinterSnowfall/d7vk/releases/tag/v1.6) and enabled it in the arm64 build.
   - Updated `dxvk-sarek` to [249c45a8](https://github.com/pythonlover02/DXVK-Sarek/commit/249c45a8) and enabled it in the arm64 build.
   - **DXVK-Sarek** is now using the very experimental [dyasync](https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation) method by default. Please use [this issue](https://github.com/CachyOS/proton-cachyos/issues/116) for problems concerning DXVK-Sarek.
   - Updated `protonfixes` to [334ffe8](https://github.com/Open-Wine-Components/umu-protonfixes/commit/334ffe8)
   - Disabled `ntsync` for Hogwarts Legacy by default.
   - Imported a few `d2d1` updates from upstream Wine.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.
> 
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260324

---

### Version 10.0-20260321
* Proton (SLR and Native)
   - Update release of the previous one, based on [`10.0-20260312`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312)
   - Update [`dxvk`](https://github.com/doitsujin/dxvk/commit/1676dcaf) and [`vkd3d-proton`](https://github.com/HansKristian-Work/vkd3d-proton/commit/c3bc3dc4) to latest.
   - Update alternative vkd3d-proton to the updated [`descriptor-heap-test`](https://github.com/HansKristian-Work/vkd3d-proton/commit/97a0c5d0) branch.
   - Update [`dxvk-sarek`](https://github.com/pythonlover02/DXVK-Sarek) to latest. [Dyasync is a very experimental](https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation) change that aims to replace `async` in DXVK-Sarek. It does not have the issues `async` while offering a comparable, if not better, experience. Please use [this issue](https://github.com/CachyOS/proton-cachyos/issues/116) for problems concerning DXVK-Sarek.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.
> 
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> * For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md
> * For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md
> * For `dxvk-sarek` specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation
> * For `dxvk-low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312

---

### Version 10.0-20260320
* Proton (SLR and Native)
   - Update release of the previous one, based on [`10.0-20260312`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312)
   - Updated [`dxvk`](https://github.com/doitsujin/dxvk/commit/973433f3) and [`vkd3d-proton`](https://github.com/HansKristian-Work/vkd3d-proton/commit/bd3f5e3d) to latest.
   - Imported the high CPU usage fix for Death Stranding 2 from upstream Proton Experimental Bleeding Edge.
   - Imported a commit from Proton-EM to stub `StorageDeviceTrimProperty`. Should fix SSDs being detected as HDDs by the Where Winds Meet standalone launcher.
   - Added patch to `protonfixes` to also check the protonfixes cache for the FSR4 DLLs before falling back to a previous version. If you happen to have versions newer than `4.0.0` in the cache, they will be used even if the remote files do not exist any more.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> For the `low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312

---

### Version 10.0-20260319
* Proton (SLR and Native)
   - Update release of the previous one, based on [`10.0-20260312`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312)
   - Bundled [DXVK-NVAPI's Vulkan Reflex layer](https://github.com/jp7677/dxvk-nvapi?tab=readme-ov-file#vulkan-reflex-layer) to support [Reflex in Vulkan](https://docs.nvidia.com/datacenter/tesla/driver-installation-guide/gaming.html#reflex-for-vulkan-steam-play-proton) games. Enable using `PROTON_VKREFLEX=1`
   - Allowed Wayland server-side decorations to work out-of-the-box. In case there is an issue due to decorations, `PROTON_NO_WM_DECORATION=1` (or the original `WAYLANDDRV_SSD=0`) will disable them.
   - Updated [DXVK](https://github.com/doitsujin/dxvk/commit/3730b707223a273fb1774f2f2ac3572d68c4dbe9) and [vkd3d-proton](https://github.com/HansKristian-Work/vkd3d-proton/commit/a2d12dd9cbeb8076248524872ada87ab4933aa66) to latest
   - Imported fixes for Crimson Desert / Death Stranding 2 from upstream Proton Experimental Bleeding Edge
   - Disabled `ntsync` for Death Stranding 2
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> For the `low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312

---

### Version 10.0-20260312
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`10.0-20260312`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312).
   - Enabled [`wine-nvml`](https://github.com/Saancreed/wine-nvml) by default for Nvidia GPUs at the request of its developer in order to get wider testing for it. `wine-nvml` allows applications running under Wine to call some NVML functions as if the native Windows driver was installed into the prefix with the purposes of monitoring GPU temperature, utilization, etc. It gives the benefits of [GPU utilization reporting](https://docs.nvidia.com/datacenter/tesla/driver-installation-guide/gaming.html#gpu-utilization-reporting-steam-play-proton) without going through the manual installation process. It can still be disabled with `PROTON_NVIDIA_NVML=0` if needed.
   - `ntsync` has been enabled by default. It can still be disabled when required with `PROTON_USE_NTSYNC=0`.
   - `gplasync` has been removed from our alternative DXVK, and with it `PROTON_DXVK_GPLASYNC`. `PROTON_DXVK_LOWLATENCY` remains, and it is the only option now.
   - Imported `winewayland.drv` updates from Proton-EM (up to [Proton-EM 10.0-34](https://github.com/Etaash-mathamsetty/Proton/releases/tag/EM-10.0-34)).
   - IME is **NOT** disabled by default on `winewayland.drv` any more, repeat keys should work now regardless.
   - Updated **D7VK** to [v1.5](https://github.com/WinterSnowfall/d7vk/releases/tag/v1.5)
   - Updated **protonfixes** to https://github.com/Open-Wine-Components/umu-protonfixes/commit/c5da693
   - Fixed the **FSR4** downloader to fallback to a previous version if the required DLL could not be found. Recently AMD removed all the `amdxcffx64.dll` versions other than `4.0.0`, so now both `PROTON_FSR4_UPGRADE` and `PROTON_FSR4_RDNA3_UPGRADE` will download that version. The downloader will try to find and download newer versions if they become available again.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> For the `low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260312

---

### Version 10.0-20260228
* Proton (SLR and Native)
   - Update release to address a few concerns around `DXVK-GPLALL` in the previous one, based on [`10.0-20260227`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260227).
   - Due to issues reported with `DXVK-GPLALL`, for example introducing lag-spikes when `gplasync` was disabled, it has been replaced with the individual patchsets from [dxvk-low-latency](https://github.com/netborg-afps/dxvk/) and [dxvk-gplasync](https://gitlab.com/Ph42oN/dxvk-gplasync/), without further modifications. Accordingly, a couple of convenience options have been introduced to exclusively enable only one of the components instead of both. We refer to this version as `dxvk-llasync` internally for convenience, but it is **NOT** a fork or its own project. The newly introduced configuration is as follows.
     | Environment variable | Description |
     |----------------------|-------------|
     | `PROTON_DXVK_LLASYNC`    | When set to `1` it will enable the alternative DXVK with default configuration. This means that both `lowlatency` and `gplasync` will be enabled. This option **SHOULD NOT** be used with anti-cheat/multiplayer games. |
     | `PROTON_DXVK_LOWLATENCY` | When set to `1` it will enable the alternative DXVK with configuration to enable only the `low-latency` component. The configuration is applied by appending to `DXVK_CONFIG` and is equivalent to `DXVK_CONFIG="dxvk.enableAsync=False"`. This option should make it safe to use with anti-cheat/multiplayer games. |
     | `PROTON_DXVK_GPLASYNC`   | When set to `1` it will enable the alternative DXVK with configuration to enable only the `gplasync` component. The configuration is applied by appending to `DXVK_CONFIG` and is equivalent to `DXVK_CONFIG="dxvk.framePace=max-frame-latency"`. This option **SHOULD NOT** be used with anti-cheat/multiplayer games. |

     When any of these options is used, the number of DXVK compiler threads is set to `NUMBER_OF_CPUS - 2` with a lower limit of `3`. I.e, if your CPU has 8 threads, DXVK will use up to 6, if your CPU has 4 threads it will use up to 3. This is meant to help with interactivity when compiling shaders during gameplay.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> For the `low-latency` related options to tune its behavior refer to: https://github.com/netborg-afps/dxvk-low-latency?tab=readme-ov-file#dxvk-low-latency
> For the `gplasync` related options to tune its behavior refer to: https://gitlab.com/Ph42oN/dxvk-gplasync/

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260227

---

### Version 10.0-20260227
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release [`10.0-20260227`](https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260227).
   - Replaced the `dxvk-gplasync` patchset with the [`dxvk-gplall`](https://github.com/Digger1955/dxvk-gplasync-lowlatency) patchset by @Digger1955, which includes both @Ph42oN's [dxvk-gplasync](https://gitlab.com/Ph42oN/dxvk-gplasync/) and @netborg-afps's [dxvk-low-latency](https://github.com/netborg-afps/dxvk/) patchsets. Since this is an exploratory change for this release, the environment switch is still `PROTON_DXVK_GPLASYNC=1`. The same warnings as the previous `dxvk-gplasync` still apply, we suggest not using this with anti-cheat or multiplayer games. If you want only the `low-latency` component, you can disable the `gplasync` component with `DXVK_CONFIG="dxvk.enableAsync=False"`. For more information refer to the project's [README](https://github.com/Digger1955/dxvk-gplasync-lowlatency?tab=readme-ov-file#additional-info).
   - Renamed the `PROTON_DXVK_DDRAW` environment variable to `PROTON_D7VK_DDRAW` to reflect the origin of the component as it is separate from DXVK.
   - Disabled IME by default when using `winewayland.drv` temporarily until https://gitlab.winehq.org/wine/wine/-/merge_requests/10007 has been merged and we can backport it.
   - Updated @Vyrolian's `winealsa` and `winepulse` patches.
   - Updated `d7vk` to https://github.com/WinterSnowfall/d7vk/tree/v1.4
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/b99bf1c
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a development version of `umu-launcher` from https://github.com/Open-Wine-Components/umu-launcher.
> From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter the `steamrt4` container to inspect it
> without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository
> https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> For DXVK-GPLALL specific options to tune its behavior refer to: https://github.com/Digger1955/dxvk-gplasync-lowlatency?tab=readme-ov-file#additional-info

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260227

---

### Version 10.0-20260207
* Proton (SLR and Native)
   - Update release to address a few minor issues of the previous one, based on `bleeding-edge`.
   - Partially re-added the DualSense haptics patchset. The hotplug support patchets are omitted as they were causing issues. Thanks to @xzn for taking an interest and providing an updated patchset.
   - Removed some faulty `print()` statements in the `proton` script that messed up parsing Proton's `stdout` when using `getnativepath`/`getcompatpath`. https://github.com/CachyOS/proton-cachyos/issues/96
   - Updated `d7vk` to https://github.com/WinterSnowfall/d7vk/tree/v1.3
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/d37ce42
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - Added workflow to build `wine-cachyos` redistributables, potentially usable by Lutris etc. Still under consideration. Thanks to @NelloKudo

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a WIP version of `umu-launcher` from https://github.com/loathingKernel/umu-launcher/tree/tool_info_arm64,
> specifically the `tool_info_arm64` branch. From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter
> the `steamrt4` container to inspect it without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-308355-20260207-p6f42a5-w1d3dc8-d00b599-v3d306e

---

### Version 10.0-20260203
* Proton (SLR and Native)
   - Update release to address a few minor issues of the previous one, based on `bleeding-edge`.
   - Removed the DualSense haptics patchset. If you are using a DualSense controller, you might need to recreate your prefixes. While the patchset itself fixed the haptics on these controllers, it broke some other games, something which the developer had already warned about but I didn't listen. Hopefully after further testing we will be able to include it again.
   - Added a `winealsa` patch for better multi-channel audio support https://github.com/CachyOS/wine-cachyos/pull/4 . Thanks to @Vyrolian, the developer of these patches and to @EPOCHvoyager for the PR.
   - The arm64 build is now part of our released assets. This is still in a testing phase and possibly broken, but it's about time to make it more easily accessible. The arm64 build doesn't include `dxvk-sarek`, `d7vk` and `nvidia-libs` but `winewayland.drv` should work. For instruction see the NOTE below.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building `arm64` packages of Proton-CachyOS for the past few versions. They are now part of the release but they are untested and possibly
> broken. To use this build you will need to get and build a WIP version of `umu-launcher` from https://github.com/loathingKernel/umu-launcher/tree/tool_info_arm64,
> specifically the `tool_info_arm64` branch. From the CLI interface it should work normally by pointing `PROTONPATH` to this proton build. If you want to enter
> the `steamrt4` container to inspect it without running proton, you can do so by running `PROTONPATH=umu-steamrt4-arm64 umu-run xterm`.
> 
> I also provide unpatched builds of Proton Experimental with support for `umu-launcher` in my personal repository https://github.com/loathingKernel/Proton/releases which can be used for testing `arm64`
> 
> We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the [CachyOS Discord server](https://discord.gg/r2C4gAdh).

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-305999-20260203-p6f42a5-w523bc2-d2f4acd-v298eaf

---

### Version 10.0-20260127
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release `10.0-20260127`.
   - Imported fixes for EA App from `steam_helper` to `umu_helper`.
   - Imported upstream wine changes to fix an issue that caused applications to hang on exit. Thanks to @NelloKudo.
   - Imported upstream wine changes to fix a crash under odd circumstances. https://github.com/CachyOS/proton-cachyos/issues/89
   - Imported some winewayland fixes from Proton-EM.
   - Updated `d7vk` to https://github.com/WinterSnowfall/d7vk/tree/9459afe6
   - Updated `dxvk-sarek` to https://github.com/pythonlover02/DXVK-Sarek/tree/b8d84197
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/ac8eeea
   - The arm64 build is now based on Valve's steamrt4 arm64 SDK instead of our local sniper arm64 SDK used previously.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use `x86_64`. The `x86_64_v2`
> and `x86_64_v3` should be absolutely identical between them and with `x86_64` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> We have been building Arm64 packages of Proton-CachyOS for the past few versions. They are not part of the release but their artifacts can be found in the
> release's workflow. We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the CachyOS Discord server.

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20260127

---

### Version 10.0-20260102
* Proton (SLR and Native)
   - Development release based on version `10.0-20260101`. Because this update is meant for testing, this release will NOT be availabe in the CachyOS repos or the AUR.
   - Add and build `d7vk` module. Use the **temporary** `PROTON_DXVK_DDRAW=1` environment variable to use `ddraw.dll` from d7vk.
   - Patched `protonfixes` to use the `default` preset when upgrading DLSS. This is supposed to allow DLSS to choose the preset to use according to the currently selected upscale mode.
   - Patched `protonfixes` and `wine` to download and redirect `libxess_dx11.dll`.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use either `x86_64`
> or `x86_64_v2`. `x86_64_v3` should be absolutely identical with `x86_64_v2` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

> [!NOTE]
> We have been building Arm64 packages of Proton-CachyOS for the past few versions. They are not part of the release but their artifacts can be found in the
> release's workflow. We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the CachyOS Discord server.

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251222

---

### Version 10.0-20260101
* Proton (SLR and Native)
   - Bugfix release based on version `10.0-20251222`.
   - Imported dualsense patches from https://github.com/xzn/proton-ds5-haptic. Development and issues are discussed in https://github.com/ValveSoftware/Proton/issues/5900
   - Re-synced a few wayland patches with Proton-EM. Due to some outdated cherry-picks, certain keyboard layouts would not work when using `winewayland.drv`.
   - Removed a long standing patch that might have been causing degraded 1% lows in some cases. Since the difference was very small, I am certain yet, but after a lot of benchmarks, 1% lows seem to be ~3fps higher consistently. Hopefully removed commit was the culprit.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/f78be4d
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!IMPORTANT]
> I know that we have a lot of different packages that might cause confusion. My suggestion is to be conservative and use either `x86_64`
> or `x86_64_v2`. `x86_64_v3` should be absolutely identical with `x86_64_v2` across the board, and `x86_64_v4` can be worse in some cases.
> Feel free to experiment and see which fits better for your system, of course.

> [!NOTE]
> We have been building Arm64 packages of Proton-CachyOS for the past few versions. They are not part of the release but their artifacts can be found in the
> release's workflow. We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the CachyOS Discord server.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251222

---

### Version 10.0-20251222
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release `10.0-20251222`.
   - The `DLSS/FSR4/FSR3/XESS` upgrade functionality has been moved into protonfixes. The options and their usage are exactly same as before.
   - When using `PROTON_FSR4_[RDNA3_]UPGRADE`, `MLFG_UPGRADE=1` will also be set by default. You can disable `MLFG` with `PROTON_MLFG_UPGRADE=0`.
   - `PROTON_FSR4_INDICATOR` now also sets `MLFG_WATERMARK=1` along with `FSR$_WATERMARK=1`.
   - When enabling `winewayland`, `ENABLE_HDR_WSI=1` will also be set automatically if and Nvidia GPU is detected. 
   - Imported a number of commits from Proton-EM that implement FSR4 MLFG.
   - Imported a number of commits from Proton-EM that implement better keyboard layout support and HDR under `winewayland`.
   - Added `WINE_BLOCK_HOSTS` to provide a list of hosts for Wine to not connect to. The list can be either comma (`,`) or semicolon (`;`) separated, i.e `WINE_BLOCK_HOSTS=host1.org,host2.net`. The maximum number of hosts is 16 and the maximum length of each host is 256 characters.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/82b2927
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> We have been building Arm64 packages of Proton-CachyOS for the past few versions. They are not part of the release but their artifacts can be found in the
> release's workflow. We are looking for testers, if you are interested, feel free to contact me (`@loathingKernel`) in the CachyOS Discord server.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251222

---

### Version 10.0-20251126
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release `10.0-202511025` (`experimental-bleeding-edge-10.0-275645-20251126-p1c3998-wdefa42-d8d58ad-vcc9e5e` to be exact).
   - Fixed an issue with Resonite caused by the recently imported wine environment changes (https://github.com/CachyOS/proton-cachyos/issues/80)
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-275645-20251126-p1c3998-wdefa42-d8d58ad-vcc9e5e

---

### Version 10.0-20251120
* Proton (SLR and Native)
   - Updated to the most recent Proton Experimental release `10.0-202511020`.
   - Fixed an issue that could cause Proton to crash when the Unix environment was too large (https://github.com/CachyOS/proton-cachyos/issues/73)
   - Added the commits from upstream wine that fix Genshin Impact and Zenless Zone Zero high CPU usage again. This time Marvel's Rivals should not crash.
   - Added a patch to fix Girls Frontline crashing on startup. Thanks to @NelloKudo.
   - Added a convinience function in Proton that emulates `DXVK/VKD3D_FRAME_RATE`. It reads the value from the removed `DXVK/VKD3D` env variables, and applies it through `DXVK_CONFIG`. This is added as a convenience and I am not certain if it will remain.
   - Added an `umu.exe` shim executable to start appliations with when using `umu-launcher`. It is derived from `steam.exe` but the Steam specific bits have been removed. It should stop Proton, and thus umu, from exiting prematurely in some cases after starting the target application.
   - Updated dxvk-sarek, dxvk-gplasync and nvidia-libs in proton to check if their respective DLLs are available in the release before including them. This allows for selectively disabling them while testing llvm/arm64 builds. Accompaning options have been added in `configure.sh` to exclude them from a build. Our released builds still include them.
   - Imported a few fixes to NTSync from upstream wine.
   - Imported more commits from upstream Wine for `d2d1`, `windowscodecs`, `vccorlib140`.
   - As usual, imported a couple of wayland-related updates from Proton-EM. This time around they should fix some keyboard input issues.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/2b33f28
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251120

---

### Version 10.0-20251107
* Proton (SLR and Native)
   - This is mostly an incremental update to the most recent Proton Experimental release `10.0-20251106b`.
   - Imported more commits from upstream Wine for `d2d1`, `windowscodecs`, `vccorlib140` and `msvcrt`.
   - As usual, imported a couple of wayland-related updates from Proton-EM.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/5771780
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251106b

---

### Version 10.0-20251023
* Proton (SLR and Native)
   - This is mostly an incremental update to the most recent Proton Experimental release.
   - Removed a few more conflicting `staging` patches which have been superseded in upstream Proton/Wine.
   - Removed dualsense related patches which have been superseded in upstream Proton/Wine.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/c8e88a9
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251023

---

### Version 10.0-20251017
* Proton (SLR and Native)
   - Added `libpcap` for the `wpcap` module in Wine.
   - Added another alternative DXVK, `dxvk-gplasync`, at the requests of our friends at Dawn Winery. Enable using `PROTON_DXVK_GPLASYNC=1`.
   - Imported patches to make Blue Protocol: Star Resonance to work. Thanks to Dawn Winery for the many sleepless nights spent on debugging and working out the issue.
   - Imported `windowscodecs` commits from upstream wine. Might help with taking screenshots in some cases.
   - Removed a few conflicting `staging` patches that have been superseded in upstream Wine. This also includes the "Hide wine version from applications" patch, as it shouldn't be needed by anything. If that's not the case, please report it by opening an issue.
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/596f977
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251017

---

### Version 10.0-20251015
* Proton (SLR and Native)
   - Just a version bump of the base proton bleeding edge version.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-255917-20251015-p30f753-w92e7a7-ddf74ab-v4ce928

---

### Version 10.0-20251008
* Proton (SLR and Native)
   - Updated DXVK to fix issues with Elite Dangerous.
   - Updated `dxvk` to https://github.com/doitsujin/dxvk/tree/df74ab52
   - Updated `vkd3d-proton` to https://github.com/HansKristian-Work/vkd3d-proton/tree/4ce92864
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251006b

---

### Version 10.0-20251007
* Proton (SLR and Native)
   - Removed a number of commits that reportedly caused issues with various games, such as Marvel's Rivals. This includes the one helping with Genshin Impact performance.
   - Re-added `DISABLE_LAYER_MESA_ANTI_LAG` when using `PROTON_FSR4_UPGRADE`.
   - Fixed an issue with nvidia-libs handling that resulted in `nvcuda.dll` missing from the prefix. This would cause DLSS Framegen to be unavailable on certain versions of `nvngx_dlssg.dll` shipped with games.
   - Updated `dxvk` to https://github.com/doitsujin/dxvk/tree/55ca713b36f02dcab391df3f847d8713e6150d3e
   - Updated `vkd3d-proton` to https://github.com/HansKristian-Work/vkd3d-proton/tree/abed356c7d6ac592641ed859b9a197b9f00266a0
   - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/898e3a8d16d180e2ca63ba7a9f750cea1fb45d51
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - None

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251006b

---

### Version 10.0-20251006
* Proton (SLR and Native)
  - Imported a couple of commits from upstream wine to fix Genshin Impact performance. Thanks to @NelloKudo.
  - Imported latest wayland-related commits from Proton-EM. They should fix dead keys when using `winewayland.drv` and DPI scaling. Thanks to @Etaash-mathamsetty.
  - Added an override for umu to use `steam.exe` instead of `start.exe` when launching applications. This is required by certain anime games on Linux. Use `UMU_USE_STEAM=1` to use this alternative path.
  - Updated the default shader cache size for Mesa to 10GB when using `PROTON_LOCAL_SHADER_CACHE=1`.
  - Updated `nvidia-libs/nvcuda` to https://github.com/SveSop/nvcuda/tree/d65952d3814453a91a7e4511ee0fd8203f3a416c
  - Updated `dxvk-sarek` to https://github.com/pythonlover02/DXVK-Sarek/tree/8843c627ffb4a32f184d5ba8100cc31999918a64
  - Updated `protonfixes` to https://github.com/open-wine-components/umu-protonfixes/tree/f7a576d59904936faa39b7ab1c9eb975d04d9aa9
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None
* Wine (Standalone)
  - Imported lsteamclient as a wine module from miniproton. 

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20251006

---

### Version 10.0-20250919
* Proton (SLR and Native)
  - DXVK is under heavy development at the moment of this release. DXVK and VKD3D-Proton have been updated to the latest version but issues might still arise. Reproduce any issues with Valve's Proton Experimental Bleeding Edge and report them upstream.
  - Updated `PROTON_(DLSS|XESS|FRS4|FSR3)_UPGRADE` cache to hold the compressed archives instead of the extracted DLLs to reduce storage requirements. If you want to remove the old files, delete `~/.cache/protonfixes/upscalers` directory, as they won't be automatically removed.
  - The per-game cache is not enabled by default any more as it seemed to cause confusion. You can enable it using `PROTON_LOCAL_SHADER_CACHE=1` if you want the previous behavior.
  - Removed `GST_GL_WINDOW=surfaceless` when enabling Wayland as it is not as compatible as `x11`. If your game spawns an invisible window on the taskbar under Wayland when playing videos, you can use the previous value to get rid of it.
  - Removed the temporary `DISABLE_LAYER_MESA_ANTI_LAG` flag when using FSR4 upgrade as Anti-Lag 2 should be working properly now. For information on why this was added in the first place refer to https://github.com/CachyOS/proton-cachyos/issues/47.
  - Updated `protonfixes` to https://github.com/Open-Wine-Components/umu-protonfixes/commit/1cec05549e2af5cf454fa748a80b76714ef2e940.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - This release won't have a native package in CachyOS repositories or the AUR. The reason is that there is too much work-in-progress in DXVK that might cause breakages, and there isn't a user-friendly way to downgrade CachyOS or AUR packages.
  - Despite the above, the source is present in the repository for anyone wanting to build it locally by modifying the existing PKGBUILD, or from my own [repository here](https://github.com/loathingKernel/PKGBUILDs/releases/tag/loathk-public).
  - Removed `piper`, `openfst`, `kaldi` and `vosk` from the build to reduce size and compile time as they were not linking correctly in the native build. They might be included again sometime in the future.
* Wine (Standalone)
  - Removed the "Disable hidraw/Enable SDL" patch as it breaks PlayStation glyphs in games with native DualSense support. You can still disable `hidraw` just like in Proton with `PROTON_DISABLE_HIDRAW=1`. Thanks to @NelloKudo.
  - Imported upstream wine patches to enable `wow64` on multilib builds using `WINEARCH=wow64`. Using `wow64` should fix games that don't play videos due to missing lib32 `ffmpeg` and `gst-plugins` in Arch/CachyOS but also might cause issues with various applications and installers.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20250919

---

### Version 10.0-20250906
* Proton (SLR and Native)
  - Fixed `PROTON_(DLSS|XESS|FRS4|FSR3)_UPGRADE` to not download developement versions of upscaler DLLs. This also introduces checksum validation for the cached and installed DLLs.
  - Fixed an issue with windows not focusing properly. This issue made `winecfg` and other similar windows unable to open drop-down menus and focus input fields.
  - Fixed an issue (CachyOS/proton-cachyos#52) with `winewayland.drv` not transitioning from windowed to fullscreen mode properly, with the resulting fullscreen window being offset from the top of the screen in some games. Thanks to @Etaash-mathamsetty.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - Removed `piper`, `openfst`, `kaldi` and `vosk` from the build to reduce size and compile time as they were not linking correctly in the native build. The might be included again sometime in the future.

> [!WARNING]
> This release includes a `x86_64_v4` package. This package is largely untested and experimental.
> It may exhibit issues or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

> [!NOTE]
> For DXVK-Sarek specific options to tune its behavior refer to: https://github.com/pythonlover02/DXVK-Sarek?tab=readme-ov-file#shader-compilation

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-238230-20250905-p786576-w3f527f-d7cb8e5-v013d33

---

### Version 10.0-20250905
* Proton (SLR and Native)
  - Extended `PROTON_(DLSS|XESS|FRS4|FSR3)_UPGRADE` infrastructure to allow version selection and also cache downloaded DLLs.
    
    | Usage description                                                                                                                                                                                                                                                                                                                                                                                                                                             |
    |---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    | These options when set to `=1` will work as before, but they will download the latest *available* version, effectively providing automatic updates.                                                                                                                                                                                                                                                                                                           |
    | Furthermore, you can force the the version to download by providing it as the variable's value instead of `1`. For example at the time of writing the latest DLSS version is `310.4.0.0`, if you want to use an earlier version you can do so by setting `PROTON_DLSS_UPGRADE="310.3.0.0"`. You can also write the version partially, and the latest version that matches will be used, i.e. `PROTON_DLSS_UPGRADE="310.2"` will download version `310.2.1.0`. |
    | For FSR4, `PROTON_FSR4_UPRGRADE=1` will download `4.0.2` by default, and `PROTON_FSR4_RDNA3_UPRGRADE=1` will download `4.0.0`. You can override the version in both cases as described above. For example, `PROTON_FSR4_UPRGRADE="4.0.0"` will use `4.0.0` and `PROTON_FSR4_RDNA3_UPRGRADE="4.0.2"` will force `4.0.2` to be used.                                                                                                                            |
    | **Note:** Some DLLs, for example the ones for XeSS and FSR3 do not have consistent versions. In this case the one that matches the specified version will be downloaded and the latest version will be downloaded for the remaining ones.                                                                                                                                                                                                                     |
    | The downloaded DLLs are cached under `~/.cache/protonfixes/upscalers` and depending on options and usage they might require a considerable amount of storage (~500MB).                                                                                                                                                                                                                                                                                        |

  - Increased the per-game shader cache size for Nvidia to 10GiB and added `__GL_SHADER_DISK_CACHE_SKIP_CLEANUP=1` to the effective environment.
  - Imported updates to `amdxc64.dll` from Proton-EM.
  - Added `PROTON_FSR4_INDICATOR` to enable the FSR4 watermark. This doesn't do anything different from `FSR4_WATERMARK` from Proton-EM, it just looked more in-line with the existing options.
  - Updated `nvidia-libs/nvcuda` and `nvidia-libs/nvenc` libraries to the latest version.
  - Re-enabled `asf` plugins for `gst-bad` and `gst-ugly`, might fix some videos not playing.
  - Updated `protonfixes` to https://github.com/Open-Wine-Components/umu-protonfixes/commit/93726321988ac2420ac7535d69972a23f0b2a40a
  - Imported wayland-related commits from upstream wine.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

> [!WARNING]
> This release introduces a `x86_64_v4` package. This package is largely untested and experimental. It may exhibit issues and or completely refuse to work. Use at your own discretion and report issues [here](https://github.com/CachyOS/proton-cachyos/issues/51) only.

> [!NOTE]
> For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

> [!NOTE]
> For FSR4 related documentation, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/FSR4.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-238230-20250905-p786576-w3f527f-d7cb8e5-v013d33

---

### Version 10.0-20250820
* Proton (SLR and Native)
  - This is a re-relese of **10.0-20250819** with some fixes.
  - Disable AMD Anti-Lag 2 temporarily when `PROTON_FSR4_(RDNA3_)UPGRADE` is used, there are currently issues when both are enabled.
  - Imported wayland-related commits from upstream wine. Might fix The Finals when winewayland is enabled.
  - Imported updates to `amdxc64.dll` from Proton-EM.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

**Note:** For wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20250819

---

### Version 10.0-20250819
* Proton (SLR and Native)
  - This is a re-release of `10.0-20250807` re-based on top of `experimental-10.0-20250819` with some additional features and fixes.
  - The `_ntsync` branch has been merged for this release as part of the `main` branch. Disabled by default.
    **Note:** To use NTSync you have to set `PROTON_USE_NTSYNC=1`. Do not trust Mangohud's indicator, it falsely reports that it is using NTSync without this environment variable while in reality it's using FSync/ESync. Verify with `lsof /dev/ntsync`. This is not the same patchset as in Proton-GE/Proton-EM, it's compatibility might differ.

  - Added [dxvk-sarek](https://github.com/pythonlover02/DXVK-Sarek) as an optional DXVK replacement for older GPUs that don't properly support Vulkan 1.3. It is using the `async` branch, so it SHOULD NOT to be used with games using anti-cheat or multiplayer games in general. You have been warned. Use `PROTON_DXVK_SAREK=1` to enable.
  - Fixed an issue with `PROTON_NVIDIA_LIBS` causing games to hang if it was enabled and then disabled.
  - Skip cache cleanup on NVIDIA for per-game shader caches.
  - Allow `DXVK_NVAPI_DRS_SETTINGS` to be overridden by the environment when `PROTON_DLSS_UPGRADE` is used.
  - Changed how upscaler DLL replacement works to allow for multiple of `PROTON_FSR4|FSR3|DLSS|XESS_UPGRADE` to work simultaneously. This is meant to accommodate software such as Optiscaler to find updated DLLs for different upscalers at the same time.
  - Added `PROTON_FSR3_UPGRADE` to upgrade FSR 3.1 DLLs to newer versions.
  - Did the usual video/audio codec whack-a-mole again, some things might work, some things might break. C' est la vie.
  - Added `PROTON_MEDIA_USE_GST` and `PROTON_GST_VIDEO_ORIENTATION` from Proton-GE to support fixes for videos with the wrong orientation.
  - Imported a few upstream commits.
  - Updated `protonfixes` to https://github.com/Open-Wine-Components/umu-protonfixes/commit/a19a272f9df3a56019b8b2914e610de4cc841087
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

**Note:** For Wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20250819

---

### Version 10.0-20250807
* Proton (SLR and Native)
  - Added downloader for XeSS dlls (version **2.1.0**), similar to the DLSS downloader. Use `PROTON_XESS_UPGRADE=1` environment variable to enable it.
  - Added `PROTON_FSR4_RDNA3_UPGRADE` for RDNA3 GPUs. Does the same thing as `PROTON_FSR4_UPGRADE` but also sets some other necessary variables.
  - Added completer implementations of Nvidia libraries missing from Proton. Should help with enabling options such as PhysX on games they were disabled before. These Nvidia libraries were integrated from https://github.com/SveSop/nvidia-libs. To enable them use `PROTON_NVIDIA_LIBS=1`.  You can also enable them individually using `PROTON_NVIDIA_NVCUDA`, `PROTON_NVIDIA_NVENC`, `PROTON_NVIDIA_NVML` and `PROTON_NVIDIA_NVOPTIX`. These are incompatible with `wow64` and thus disabled when `PROTON_USE_WOW64=1` is set.

    **Important**: If you are using RTX series 4000 or 5000 GPUs you might encounter bad performance or crashes when enabling these with 32bit games. Use`PROTON_NVIDIA_LIBS_NO_32BIT=1` with any of the options above to disable the 32bit and use the 64bit libraries only. Some 32bit games on RTX 4000 and above might still exhibit bad performance with these libraries enabled, e.g. Mirror's Edge.

    **Note**: It is advised that you report issues with these libraries in their respective issue trackers, [nvcuda](https://github.com/SveSop/nvcuda/issues), [nvenc](https://github.com/SveSop/nvenc/issues), [wine-nvml](https://github.com/Saancreed/wine-nvml/issues) and [wine-nvoptix](https://github.com/SveSop/wine-nvoptix/issues). If you don't know what is causing the problem, feel free to open an issue in [proton-cachyos](https://github.com/CachyOS/proton-cachyos/issues) instead.
  - Added per-game shader cache, enabled by default, can be disabled with `PROTON_LOCAL_SHADER_CACHE=0`. Shaders will be cached under `<steamlibrary>/shadercache/<appid>` for each game, similarly to when shader pre-caching is enabled. You will get stuttering as the shader cache for each game is rebuilt but the cached shaders won't be evicted due to limited cache size.
  - Ensured that the codecs in FFmpeg match what Valve has enabled in theirs. We still enable more but now we should not miss any by chance.
  - Disabled `codecalpha` from gst-bad which was causing issues with some games with WebM videos when Wine is built with FFmpeg, and re-enabled `winedmo`.
  - Imported wayland related commits from Proton-EM ([up to EM-10.0-2B](https://github.com/Etaash-mathamsetty/Proton/tree/EM-10.0-2B)).
  - Imported a few upstream commits.
  - Fix `protonfixes` not de-symlinking prefix files properly. Should fix issues with installing some winetricks verbs.
  - Updated protonfixes to https://github.com/Open-Wine-Components/umu-protonfixes/commit/5cdfd3608d513bc9ff9c2d1a642ebd85687fbc1e
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

**Note:** There is a testing version with NTSync available here:
* https://share.cachyos.org/proton/proton-cachyos-10.0-20250807-slr-ntsync-x86_64.tar.xz
* https://share.cachyos.org/proton/proton-cachyos-10.0-20250807-slr-ntsync-x86_64_v3.tar.xz

To use NTSync you have to set `PROTON_USE_NTSYNC=1`. Do not trust `mangohud`'s indicator, it falsely reports that it is using NTSync without this
environment variable while in reality it's using FSync/ESync. Verify with `lsof /dev/ntsync`. We want to be certain it doesn't cause regressions
hence we are not including it with in the main packages. This is not the same patchset as in Proton-GE/Proton-EM, it's compatibility might differ.

**Note:** For wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-228005-20250807-p29548f-w253fb0-d835e98c-vb72e62

---

### Version 10.0-20250714
* Proton (SLR and Native)
  - Added downloader for DLSS dlls (version **310.3.0**), similar to the FSR4 downloader. Use `PROTON_DLSS_UPGRADE=1` environment variable to enable it.
  - Added `PROTON_DLSS_INDICATOR=1` environment variable to enable DLSS hud.
  - Reverted `PROTON_FSR4_UPGRADE=1` downloader to install version **4.0.0** of `amdxcffx64.dll`.
  - Imported wayland related commits from Proton-EM.
  - Updated protonfixes to https://github.com/Open-Wine-Components/umu-protonfixes/commit/cf8d5a2ef83d09f84ba4fa475b01b889d97f6300
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

**Note:** There is a testing version with NTSync available here: https://share.cachyos.org/proton/proton-cachyos-10.0-20250714-ntsync-slr.tar.xz
To use NTSync you have to set `PROTON_USE_NTSYNC=1`. Do not trust `mangohud`'s indicator, it falsely reports that it is using NTSync without this environment variable while in reality it's using FSync/ESync. Verify with `lsof /dev/ntsync`. We want to be certain it doesn't cause regressions hence we are not including it with in the main packages. This is not the same patch-set as in Proton-GE/Proton-EM, it's compatibility might differ.

For wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-220315-20250715-pe2a550-wef1fe3-d614d6a-v6f32f6

---

### Version 10.0-20250702
* Proton (SLR and Native)
  - Imported upstream wine commits for wayland.
  - Added a missing patch for Vanguard: Saga of Heroes.
  - Updated `amdxcffx64.dll` downloader to install version `4.0.1`.
  - Added patches for AMD's Anti Lag 2 for `vkd3d-proton` and `wine`. Requires patched `Mesa`.
  - Added `PROTON_ENABLE_MEDIACONV` env variable to enable proton mediaconverter. Mostly for testing purposes.
  - Updated protonfixes to https://github.com/Open-Wine-Components/umu-protonfixes/commit/4d51fad0b5f897a87d46cf69a8bf53fa0a0df48b
  - Added patch for protonfixes to use `vcrun2022` instead of `vcrun2019`. Fixes winetricks forcing Windows 7 as the version of the prefix.
* Proton (SLR specific)
  - Revert to `-O2` (the default) instead of `-O3`. It wasn't an issue for the SLR build but prefer to have less variance between builds.
* Proton (Native specific)
  - None

For wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-215098-20250702-pefce1a-wf6650a-deb0d67-v3a3642

---

### Version 10.0-20250623
* Proton (SLR and Native)
  - Imported wayland specific patches from Proton-EM. Thanks to [Etaash-mathamsetty](https://github.com/Etaash-mathamsetty).
  - Imported upstream patches for d2d1 since wine-10.0. Fixes "Sickly Days and Summer Traces". Thanks to [R1kaB3rN](https://github.com/R1kaB3rN).
  - Imported more upstream commits relating to wayland.
  - Added patches to help with better anticheat integration. Thanks to [NelloKudo](https://github.com/NelloKudo/) et al.
  - Added automatic download for `amdxcffx64.dll` using `PROTON_FSR4_UPGRADE`.
  - Disabled winedmo (ffmpeg) for Wine. Fixes crash in Devil May Cry HD Collection.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

For wayland specific flags and options, please refer to: https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-211434-20250623-p534f89-w293d64-de4989d-v59e50c

---

### Version 10.0-20250605
* Proton (SLR and Native)
  - Disable proton media converter by default in Wine. We ship more than enough codecs to not need it. This affects standalone Wine mostly, since in Proton it was already being disabled through the related environment variables.
  - Set `GST_GL_WINDOW` to `surfaceless` instead of `x11` in Wine. Again, mostly affects standalone Wine.
  - Update wayland specific patches.
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - None

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-206012-20250606-pc3a07e-wac8f23-d09e4bc-v4a0688

---

### Version 10.0-20250601
* Proton (SLR and Native)
  - FFmpeg has been bumped from `6.1.2` to `7.1.1`
  - Every decoder, demuxer, parser, filter has been enabled in FFmpeg
  - GStreamer and gst-plugins have been bumped to `1.26.1`
  - Updated protonfixes to https://github.com/Open-Wine-Components/umu-protonfixes/commit/50a611291caf0527b89dc55602afe66070d6c544
  - Imported new Wayland related patches from [Proton-EM-10.0-19](https://github.com/Etaash-mathamsetty/Proton/releases/tag/EM-10.0-19)
  - Ignore steam input virtual controller when PROTON_PREFER_SDL is set (thanks to [Etaash-mathamsetty](https://github.com/Etaash-mathamsetty))
* Proton (SLR specific)
  - None
* Proton (Native specific)
  - Build openfst,kaldi,vosk,piper for native version again (they are still not found while building, so no support in wine yet)
  - Clean up Steam's default Scout environment when using the native version of `proton-cachyos`

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-204012-20250601-pdce981-w6a4d0d-d4f47cb-vf96654

---

### Version 10.0-20250520
* Proton
  - Enable application-specific workarounds when using the Wayland driver by default
  - Remove media converter from `winedmo` and reenable FFmpeg for Wine, bump it to 6.1.2.
  - Import patches from Proton-EM to disable mouse acceleration, enable touchpad scrolling, and handling of rotated screens.
  - Revert to using Valve's Sniper SDK since we do not need to build `python-xlib` presently, and for transparency.

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-199576-20250520-p6aacad-w900d43-d61b91e-v7e829e

---

### Version 10.0-20250515
* Proton
  - HDR is NOT enabled by default with Wayland any more, use `PROTON_ENABLE_HDR=1` to enable when enabling Wayland.
  - Added wayland-specific command line arguments for various launchers under wayland. Thanks [Etaash-mathamsetty](https://github.com/Etaash-mathamsetty)
  - Added patches to use system cursor shapes when possible. MR: https://gitlab.winehq.org/wine/wine/-/merge_requests/7678
  - Fix issue with libvkd3d related crashes in UnderRail.
  - Fix issue with libvkd3d missing from the default prefix in the native version.
  - Fix issue with libxkbcommon trying to install bash completion related files to the host while building.
  - Use UMU SDK to build the Steam Linux Runtime version

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-bleeding-edge-10.0-198042-20250515-pba2272-w88783e-de9eff9-vb57878

---

### Version 10.0-20250509
* Proton
  - Rebased almost all patches from **Proton Cachyos 9.0**.
  - Enabled the Wayland driver for the Steam Linux Runtime builds too. Enable with `PROTON_ENABLE_WAYLAND=1`. Thanks to [GloriousEggroll](https://github.com/GloriousEggroll) for making it happen.
  - Added a lot of Wayland related patches from upstream wine that happened after the release of wine-10.0
  - Fixed various issues with the Wayland driver and Vulkan games. Thanks to [Etaash-mathamsetty](https://github.com/Etaash-mathamsetty) for all the hard work.
  - Added a stub implementation for `amdxc64.dll` to enable FSR4. Use `FSR4_UPGRADE=1` to upgrade FSR3.1 games to FSR4. Again thanks to [Etaash-mathamsetty](https://github.com/Etaash-mathamsetty). Instructions: https://github.com/Etaash-mathamsetty/wine-builds/releases/tag/fsr4
  - Added DualSense related patches for more complete audio device detection functionality for wired sound-based haptics. Some games that relied on that specific behaviour should now have that functional. Thanks to [ClearlyClaire](https://github.com/ClearlyClaire) for the original patches and [Exotic0015](https://github.com/Exotic0015) for looking into it since **Proton Cachyos 9.0**. Upstream: https://gitlab.winehq.org/wine/wine/-/merge_requests/7238
  - Removed the Dragon Age Inquisition patch as it was not working. Please use **Proton-Cachyos 9.0** for now with that game.
  - Updated the NTSync branch to Proton 10.0. Thanks to [whrvt](https://github.com/whrvt). No, NTSync is not merged into Proton-CachyOS yet, sorry.

  - Thanks to everyone on the CachyOS Discord server who provided testing while working on this. And special thanks to the people mentioned above and [NelloKudo](https://github.com/NelloKudo/) for sharing the workload.

**Base:** https://github.com/ValveSoftware/Proton/tree/experimental-10.0-20250509

---
