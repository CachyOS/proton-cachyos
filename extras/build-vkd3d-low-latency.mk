##
## vkd3d-low-latency
##

ifeq ($(findstring vkd3d-low-latency,$(WITHOUT_EXTRAS)),)

# wine builds DLLs with the same names, we need to differentiate the timestamps
VKD3D_LOW_LATENCY_i386_SOURCE_DATE_EPOCH := $(shell expr $(i386_SOURCE_DATE_EPOCH) - 2)
VKD3D_LOW_LATENCY_x86_64_SOURCE_DATE_EPOCH := $(shell expr $(x86_64_SOURCE_DATE_EPOCH) - 2)
VKD3D_LOW_LATENCY_arm64ec_SOURCE_DATE_EPOCH := $(shell expr $(arm64ec_SOURCE_DATE_EPOCH) - 2)

VKD3D_LOW_LATENCY_SOURCE_ARGS = \
  --exclude vkd3d_build.h.in \
  --exclude vkd3d_version.h.in \

VKD3D_LOW_LATENCY_MESON_ARGS = -Db_ndebug=true -Denable_extended_emulation=true
VKD3D_LOW_LATENCY_i386_MESON_ARGS = --bindir=$(VKD3D_LOW_LATENCY_i386_DST)/lib/wine/vkd3d-low-latency/i386-windows
VKD3D_LOW_LATENCY_x86_64_MESON_ARGS = --bindir=$(VKD3D_LOW_LATENCY_x86_64_DST)/lib/wine/vkd3d-low-latency/x86_64-windows
VKD3D_LOW_LATENCY_arm64ec_MESON_ARGS = --bindir=$(VKD3D_LOW_LATENCY_arm64ec_DST)/lib/wine/vkd3d-low-latency/aarch64-windows
VKD3D_LOW_LATENCY_HOST_DEPENDS = glslang

ifneq ($(UNSTRIPPED_BUILD),)
	VKD3D_LOW_LATENCY_MESON_ARGS = -Denable_trace=true
endif

VKD3D_LOW_LATENCY_i386_CFLAGS = -O3 $(i386_SANITY_FLAGS)
VKD3D_LOW_LATENCY_x86_64_CFLAGS = -O3
VKD3D_LOW_LATENCY_CPPFLAGS = -msse -msse2
VKD3D_LOW_LATENCY_LDFLAGS = -static -static-libgcc -static-libstdc++

$(eval $(call rules-source,vkd3d-low-latency,$(SRCDIR)/extras/vkd3d-low-latency))
$(eval $(call rules-meson,vkd3d-low-latency,i386,windows))
$(eval $(call rules-meson,vkd3d-low-latency,x86_64,windows))
$(eval $(call rules-meson,vkd3d-low-latency,arm64ec,windows))

$(OBJ)/.vkd3d-low-latency-post-source: patches-source
	$(foreach p,$(shell find $(PATCHES_SRC)/extras/vkd3d-low-latency/ -name "*.patch" | sort),patch -d $(VKD3D_LOW_LATENCY_SRC) -Np1 -i $(p) &&) true
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/extras/vkd3d-low-latency describe --always --exclude=* --abbrev=15 --dirty=0)#' \
	    $(SRCDIR)/extras/vkd3d-low-latency/vkd3d_build.h.in > $(VKD3D_LOW_LATENCY_SRC)/vkd3d_build.h.in
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/extras/vkd3d-low-latency describe --always --tags --dirty=+)#' \
	    $(SRCDIR)/extras/vkd3d-low-latency/vkd3d_version.h.in > $(VKD3D_LOW_LATENCY_SRC)/vkd3d_version.h.in
	mkdir -p $(DST_LIBDIR)/wine/vkd3d-low-latency
	rm -rf $(DST_LIBDIR)/wine/vkd3d-low-latency/version
	echo "$(shell git -C $(SRCDIR) submodule status -- extras/vkd3d-low-latency)" > $(DST_LIBDIR)/wine/vkd3d-low-latency/version
	touch $@

default_pfx: vkd3d-low-latency

endif # WITHOUT_EXTRAS
