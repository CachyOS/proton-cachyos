Introduction
------------

**Proton** is a tool for use with the Steam client which allows games which are
exclusive to Windows to run on the Linux operating system. It uses Wine to
facilitate this.

**Most users should use Proton provided by the Steam Client itself.** See
[this Steam Community post][steam-play-introduction] for more details.

The source code is provided to enable advanced users the ability to alter
Proton. For example, some users may wish to use a different version of Wine
with a particular title.

**The changelog** is available on [our wiki][changelog].

[steam-play-introduction]: https://steamcommunity.com/games/221410/announcements/detail/1696055855739350561
[changelog]: https://github.com/ValveSoftware/Proton/wiki/Changelog


Obtaining Proton sources
------------------------

Acquire Proton's source by cloning <https://github.com/ValveSoftware/Proton>
and checking out the branch you desire.

You can clone the latest Proton to your system with this command:

```bash
git clone --recurse-submodules https://github.com/ValveSoftware/Proton.git proton
```

Be sure to update submodules when switching between branches:

```bash
git checkout experimental_6.3
git submodule update --init --recursive
```

If you want to change any subcomponent, now is the time to do so. For
example, if you wish to make changes to Wine, you would apply them to the
`wine/` directory.


Building Proton
---------------

Most of Proton builds inside the Proton SDK container with very few
dependencies on the host side.

## Preparing the build environment

You need either a Docker or a Podman setup which Proton's build system uses
internally. You should never need to use either container engine manually unless
working on those parts of build system directly.

We highly recommend [the rootless Podman setup][rootless-podman]. Please refer
to your distribution's documentation for setup instructions (e.g. Arch
[Podman][arch-podman] / [Docker][arch-docker], Debian [Podman][debian-podman] /
[Docker][debian-docker]).

[rootless-podman]: https://github.com/containers/podman/blob/main/docs/tutorials/rootless_tutorial.md
[arch-podman]: https://wiki.archlinux.org/title/Podman
[arch-docker]: https://wiki.archlinux.org/title/Docker
[debian-podman]: https://wiki.debian.org/Podman
[debian-docker]: https://wiki.debian.org/Docker


## The Easy Way

We provide a top-level Makefile which will execute most of the build commands
for you.

After checking out the repository and updating its submodules, assuming that
you have a working Docker or Podman setup, you can build and install Proton
with a simple:

```bash
make install
```

If your build system is missing dependencies, it will fail quickly with a clear
error message.

After the build finishes, you may need to restart the Steam client to see the
new Proton tool. The tool's name in the Steam client will be based on the
currently checked out branch of Proton. You can override this name using the
`build_name` variable.

See `make help` for other build targets and options.



## Manual building

### Configuring the build

```bash
mkdir ../build && cd ../build
../proton/configure.sh --enable-ccache --build-name=my_build
```

Running `configure.sh` will create a `Makefile` allowing you to build Proton.
The scripts checks if containers are functional and prompt you if any
host-side dependencies are missing. You should run the command from a
directory created specifically for your build.

The configuration script tries to discover a working Docker or Podman setup
to use, but you can force a compatible engine with
`--container-engine=<executable_name>`.

You can enable ccache with `--enable-cache` flag. This will mount your
`$CCACHE_DIR` or `$HOME/.ccache` inside the container.

`--proton-sdk-image=registry.gitlab.steamos.cloud/proton/soldier/sdk:<version>`
can be used to build with a custom version of the Proton SDK images.

Check `--help` for other configuration options.

NOTE: If **SELinux** is in use, the Proton build container may fail to access
your user's files. This is caused by [SELinux's filesystem
labels][selinux-labels]. You may pass the `--relabel-volumes` switch to
configure to cause the [container engine to relabel its
bind-mounts][bind-mounts] and allow access to those files from within the
container. This can be dangerous when used with system directories. Proceed
with caution and refer your container engine's manual.

[selinux-labels]: https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/6/html/security-enhanced_linux/sect-security-enhanced_linux-working_with_selinux-selinux_contexts_labeling_files
[bind-mounts]: https://docs.docker.com/storage/bind-mounts/


### Building

```
make
```

**Important make targets:**

`make install` - install Proton into your user's Steam directory, see the [install Proton
locally](#install-proton-locally) section for details.

`make redist` - create a redistribute build (`redist/`) that can be copied to
`~/.steam/root/compatibilitytools.d/`.

`make deploy` - create a deployment build (`deploy/`). This is what we use to
deploy Proton to Steam users via Steamworks.

`make module=<module> module` - build both 32- and 64-bit versions of the
specified wine module. This allows rapid iteration on one module. This target
is only useful after building Proton.

`make dxvk` / `make vkd3d-proton` - rebuild DXVK / vkd3d-proton.


### Figuring Out What Failed To Build

Proton build system invokes builds of many subprojects in parallel. If one
subprojects fails there can be thousands of lines printed by other sub-builds
before the top level exits. This can make the real reason of the build failing
hard to find.

Appending `2>&1 | tee build.log` will log the full build output to a `build.log`
file. Searching that file from the bottom up for occurrences of `Error` should
point to the right area. E.g.:

```
make 2>&1 | tee build.log
grep -n '] Error [0-9]' build.log
```

```
11220:make: *** [../Makefile.in:465: /builds/proton/proton/build-dir/.kaldi-i386-configure] Error 1
12427:make: *** [../Makefile.in:1323: deploy] Error 2
```


### Debug Builds

To prevent symbol stripping add `UNSTRIPPED_BUILD=1` to the `make`
invocation. This should be used only with a clean build directory.

E.g.:

```
mkdir ../debug-proton-build && cd ../debug-proton-build
../proton/configure.sh --enable-ccache --build-name=debug_build
make UNSTRIPPED_BUILD=1 install
```


### ARM64 Builds

You need an ARM64 build machine and pass `--target-arch=arm64` to `configure.sh`.

It's not possible to use the resulting builds in x86 Steam running via FEX.


Install Proton locally
----------------------

Steam ships with several versions of Proton, which games will use by default or
that you can select in Steam Settings' Steam Play page. Steam also supports
running games with local builds of Proton, which you can install on your
machine.

To install a local build of Proton into Steam, make a new directory in
`~/.steam/root/compatibilitytools.d/` with a tool name of your choosing and
place the directory containing your redistributable build under that path.

The `make install` target will perform this task for you, installing the
Proton build into the Steam folder for the current user. You will have to
restart the Steam client for it to pick up on a new tool.

A correct local tool installation should look similar to this:

```
compatibilitytools.d/my_proton/
├── compatibilitytool.vdf
├── filelock.py
├── LICENSE
├── proton
├── proton_dist.tar
├── toolmanifest.vdf
├── user_settings.sample.py
└── version
```

To enable your local build in Steam, go to the Steam Play section of the
Settings window. If the build was correctly installed, you should see
"proton-localbuild" in the drop-down list of compatibility tools.

Each component of this software is used under the terms of their licenses.
See the `LICENSE` files here, as well as the `LICENSE`, `COPYING`, etc files
in each submodule and directory for details. If you distribute a built
version of Proton to other users, you must adhere to the terms of these
licenses.


Debugging
---------

Proton builds have their symbols stripped by default. You can switch to
"debug" beta branch in Steam (search for Proton in your library,
Properties... -> BETAS -> select "debug") or build without stripping (see
[Debug Builds section](#debug-builds)).

The symbols are provided through the accompanying `.debug` files which may
need to be explicitly loaded by the debugging tools. For GDB there's a helper
script `wine/tools/gdbinit.py` (source it) that provides `load-symbol-files`
(or `lsf` for short) command which loads the symbols for all the mapped files.

For tips on debugging see [docs/DEBUGGING-LINUX.md](docs/DEBUGGING-LINUX.md)
and [docs/DEBUGGING-WINDOWS.md](docs/DEBUGGING-WINDOWS.md).


`compile_commands.json`
-----------------------

For use with [clangd](https://clangd.llvm.org/) LSP server and similar tooling.

Projects built using cmake or meson (e.g. vkd3d-proton) automatically come with
`compile_commands.json`. Wine also generates the file on its own via `makedep`.

Proton's build system collects all the `compile_commands.json` files in a build
subdirectory named `compile_commands/`.

The paths are translated to point to the real source (i.e. not the rsynced
copy). It still may depend on build directory for things like auto-generated
`config.h` though and for wine it may be beneficial to run `tools/make_requests`
in you source directories as those changes are not committed.

You can then configure your editor to use that file for clangd in a few ways:

1) directly - some editors/plugins allow you to specify the path to `compile_commands.json`
2) via `.clangd` file, e.g.
```bash
cd src/proton/wine/
cat > .clangd <<EOF
CompileFlags:
  CompilationDatabase: ../build/current-dev/compile_commands/wine-x86_64/
EOF
```
3) by symlinking:
```bash
ln -s ../build/current-dev/compile_commands/wine-x86_64/compile_commands.json .
```


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

To enable an option, set the variable to a non-`0` value.  To disable an
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
| `fsr4`               | `PROTON_FSR4_UPGRADE`          | Automatically download `amdxcffx64.dll` and upgrade games with FSR 3.1 to use FSR 4. Version to download can be specified by supplying it as a value, like so `PROTON_FSR4_UPGRADE="4.0.1"`, instead of `1`. Downloads the latest available and known-good version of the required DLL by default. If you want to use custom DLLs refer [to this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#manually-providing-amdxcffx64dll).                          |
| `fsr4hud`            | `PROTON_FSR4_INDICATOR`        | Enable the FSR4 watermark at the top left portion of the screen. This is a shorthand option for setting `FSR4_WATERMARK=1` and `MLFG_WATERMARK=1`.                                                                                                                                                                                                                                                                                                                                 |
| `fsr4rdna3`          | `PROTON_FSR4_RDNA3_UPGRADE`    | Identical to `PROTON_FSR4_UPGRADE` but for RDNA3 GPUs. Enables some required compatibility options and downloads version `4.0.0` of the DLL by default. If you want to use custom DLLs refer [to this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#manually-providing-amdxcffx64dll).                                                                                                                                                                     |
| `mlfg`               | `PROTON_MLFG_UPGRADE`          | Enables the use of MLFG when `amdxcffx64.dll` >= `4.0.3`. This option is enabled automatically with `PROTON_FSR4_UPGRADE` and `PROTON_FSR4_RDNA3_UPGRADE`. If you need to disable it while still using the FSR4 upgrade options, you can add `PROTON_MLFG_UPRADE=0`.                                                                                                                                                                                                               |
| `fsr3`               | `PROTON_FSR3_UPGRADE`          |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `dlss`               | `PROTON_DLSS_UPGRADE`          | Automatically download and use newer versions of `nvngx_dlss(d\|g).dll` DLLs. Version to download can be specified by supplying it as a value, like so `PROTON_DLSS_UPGRADE="310.2"`, instead of `1`, to download version `310.2.1.0`. This option also sets `DXVK_NVAPI_DRS_SETTINGS` to use the latest preset. If you provide your own configuration through this environment variable, your configuration will override the defaults.                                           |
| `dlsshud`            | `PROTON_DLSS_INDICATOR`        | Enable the DLSS overlay at the bottom left portion of the screen.                                                                                                                                                                                                                                                                                                                                                                                                                  |
| `xess`               | `PROTON_XESS_UPGRADE`          |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `nvidialibs`         | `PROTON_NVIDIA_LIBS`           | Enable [alternative implementations of Nvidia libraries](https://github.com/SveSop/nvidia-libs) missing from Proton. Allows things like hardware-accelerated PhysX to function. This option enables all of `nvcuda`, `nvenc`, `nvml` and `nvoptix`. These are incompatible with `wow64` and thus disabled when `PROTON_USE_WOW64=1` is set.                                                                                                                                        |
| `nvidialibsno32`     | `PROTON_NVIDIA_LIBS_NO_32BIT`  | Use with the previous option, to enable only the 64bit nvidia libraries. Useful if you are using RTX series 4000 or 5000 GPUs and you had bad performance or crashes when enabling these with 32bit games.                                                                                                                                                                                                                                                                         |
| `nvcuda`             | `PROTON_NVIDIA_NVCUDA`         | Enable alternative `nvcuda.dll` [from nvidial-libs](https://github.com/SveSop/nvcuda) only.                                                                                                                                                                                                                                                                                                                                                                                        |
| `nvenc`              | `PROTON_NVIDIA_NVENC`          | Enable alternative `nvcencodeapi(64).dll` [from nvidial-libs](https://github.com/SveSop/nvenc) only.                                                                                                                                                                                                                                                                                                                                                                               |
| `nvml`               | `PROTON_NVIDIA_NVML`           | Enable alternative `nvml.dll` [from nvidial-libs](https://github.com/Saancreed/wine-nvml) only. This option is enabled by default.                                                                                                                                                                                                                                                                                                                                                 |
| `nvoptix`            | `PROTON_NVIDIA_NVOPTIX`        | Enable alternative `nvoptix.dll` [from nvidial-libs](https://github.com/SveSop/wine-nvoptix) only.                                                                                                                                                                                                                                                                                                                                                                                 |
| `vkreflex`           | `PROTON_VKREFLEX`              | Enables [DXVK-NVAPI's Vulkan Reflex layer](https://github.com/jp7677/dxvk-nvapi?tab=readme-ov-file#vulkan-reflex-layer) to support [Reflex in Vulkan](https://docs.nvidia.com/datacenter/tesla/driver-installation-guide/gaming.html#reflex-for-vulkan-steam-play-proton) games. It's meant to enable Reflex in games such as Portal RTX, Path of Exile 1 and 2 and Doom TDA, etc.                                                                                                 |
| `mediaconv`          | `PROTON_ENABLE_MEDIACONV`      | For debugging purposes, do not use.                                                                                                                                                                                                                                                                                                                                                                                                                                                |
|                      | `PROTON_MEDIA_USE_GST`         | Fixes video/audio playback in cutscenes in some cases.                                                                                                                                                                                                                                                                                                                                                                                                                             |
|                      | `PROTON_GST_VIDEO_ORIENTATION` | Change the orientation (rotation) of videos rendered using gstreamer. The accepted values are [the same as gstreamer's `videoflip` plugin](https://gstreamer.freedesktop.org/documentation/videofilter/videoflip.html?gi-language=c#named-constant)                                                                                                                                                                                                                                |
| `nowmdecoration`     | `PROTON_NO_WM_DECORATION`      | Disable window decorations by the the window manager, use wine's own window decorations.                                                                                                                                                                                                                                                                                                                                                                                           |
| `wayland`            | `PROTON_ENABLE_WAYLAND`        | Enable Wayland support. `winewayland` is experimental and work-in-progress, expect issues. When reporting issues ALWAYS mention if you using this environment variable, and make sure the issue still happens without it. Valve's Protons do not include `winewayland.drv`, they always use `winex11.drv`. For more information refer to [this section](https://github.com/CachyOS/proton-cachyos?tab=readme-ov-file#proton-wayland-quirks)                                        |
| `wayland`            | `PROTON_USE_WAYLAND`           | Alias of `PROTON_ENABLE_WAYLAND`                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| `hdr`                | `DXVK_HDR`                     | Enable HDR support.                                                                                                                                                                                                                                                                                                                                                                                                                                                                |
| `sdlinput`           | `PROTON_PREFER_SDL`            | Uses SDL input instead of HIDRAW/Steam Input                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| `sdlinput`           | `PROTON_USE_SDL`               | Alias of `PROTON_PREFER_SDL`                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
|                      | `PROTON_NO_STEAMINPUT`         |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| `localshadercache`   | `PROTON_LOCAL_SHADER_CACHE`    | Enable per-game shader cache even if "Shader Pre-caching" is disabled. Any configuration set by this option can be overriden, i.e. if one of the environment variables is already set, the user-set value will be used. The default configuration is set up to mimic Steam's "Shader Pre-Caching", with shaders being cached under `<steamlibrary>/shadercache/<appid>` for each game.                                                                                             |

### Proton wayland quirks
If something that uses Electron/CEF (launchers like Battle.net, Ubisoft Connect, EA App, Rockstar Launcher) doesn't work (displays as white window) after enabling native Wayland support, try adding `--in-process-gpu` to the command arguments. If you encounter controller issues with `winewayland.drv`, try using `PROTON_USE_SDL=1`, or running Steam with `-steamos3` which might allow Steam Input to work. For other options relating to `winewayland.drv` refer to [Proton-EM documentation](https://github.com/Etaash-mathamsetty/Proton/blob/em-10/docs/EM-ADDITIONS.md)

**NOTE:** The automated wayland hacks that were included in Proton 10 have been removed on purpose pending a proper implementation. This is the reason previous versions seemed to work but in Proton 11 some launchers display as a white window.

### Manually providing `amdxcffx64.dll`
In case you want to manually provide the `amdxcffx64.dll` DLL, there are two ways to achieve it.
* **The manual way:** Copy the DLL you want to use in `<compatdata>/pfx/drive_c/windows/system32/amdxcffx64.dll` and set `FSR4_UPGRADE=1`, `MFLG_UPGRADE=1` and `DXIL_SPIRV_CONFIG="wmma_rdna3_workaround"` (**ONLY** for RDNA3). Make sure to remove `PROTON_FSR4_UPGRADE` and `PROTON_FSR4_RDNA3_UPGRADE` from your environemnt.
* **The re-usable way:** Copy the DLL you want to use into `~/.cache/protonfixes/upscalers/` with the filename `amdxcffx64_v4.0.0_67A4D2BC10ad000.dll` (needs to be exactly like this, it's case-sensitive), and the use `PROTON_FSR4_UPGRADE=4.0.0` or `PROTON_FSR4_RDNA3_UPGRADE=4.0.0` and the downloader will use the cached DLL. This will only work for new prefixes or if the previous version was a different version, it will not work if the DLL is already present in the prefix.
* **The re-usable way++:** You can also do the same thing for all other DLLs. After you source your own dlls you can copy them into `~/.cache/protonfixes/upscalers` with one of the follwing names

    - `amdxcffx64_v4.0.0_67A4D2BC10ad000.dll`
    - `amdxcffx64_v4.0.1_67D435F7d97000.dll`
    - `amdxcffx64_v4.0.2_68840348eb8000.dll`
    - `amdxcffx64_v4.0.3_6930960536b9000.dll`
    - `amdxcffx64_v4.1.0_69A0952A304a000.dll`

  each one representing their respective version. You can use the version you want through `PROTON_FSR4_[_RDNA3]UPGRADE=<version>` where version one of `4.0.0`, `4.0.1`, `4.0.2`, `4.0.3` or `4.1.0`.

Other Useful Config Options
----------------------
| Compat config string | Environment Variable          | Description                                                                                                                                                                                                                                                                                                                                                                                          |
|:---------------------|:------------------------------|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                      | `GST_GL_WINDOW`               |                                                                                                                                                                                                                                                                                                                                                                                                      |
|                      | `DISABLE_LAYER_MESA_ANTI_LAG` |                                                                                                                                                                                                                                                                                                                                                                                                      |
|                      | `WINE_BLOCK_HOSTS`            | Provides a list of hosts for Wine to not connect to. The list can be either comma (`,`) or semicolon (`;`) separated, i.e `WINE_BLOCK_HOSTS=host1.org,host2.net`. The maximum number of hosts is 16 and the maximum length of each host is 256 characters.                                                                                                                                           |
|                      | `WINEALSA_CHANNELS`           | Allows to select more than two channels with the winealsa driver as well as force disable spatial audio in games. Can be useful with surround setups or when the sounds come out wrong positionally (like dialogue coming out only from the left speaker). Possible values is the number of speakers, such as `2` (to disable spatial audio), such as `4` (2 front, 2 rear), `6` (5.1) or `8` (7.1). |
|                      | `WINEALSA_SPATIAL`            | Properly downmixes spatial with `winealsa` and includes the height channels. Use `1` to enable, `0` to disable (default). Recommended only if there are spatial audio errors with the `WINEALSA_CHANNELS` variable                                                                                                                                                                                   |

<!-- Target:  GitHub Flavor Markdown.  To test locally:  pandoc -f markdown_github -t html README.md  -->
