##
## dxvk-low-latency
##

ifeq ($(findstring dxvk-low-latency,$(WITHOUT_EXTRAS)),)

# wine builds DLLs with the same names, we need to differentiate the timestamps
DXVK_LOW_LATENCY_i386_SOURCE_DATE_EPOCH := $(shell expr $(i386_SOURCE_DATE_EPOCH) - 1)
DXVK_LOW_LATENCY_x86_64_SOURCE_DATE_EPOCH := $(shell expr $(x86_64_SOURCE_DATE_EPOCH) - 1)
DXVK_LOW_LATENCY_arm64ec_SOURCE_DATE_EPOCH := $(shell expr $(arm64ec_SOURCE_DATE_EPOCH) - 1)

DXVK_LOW_LATENCY_SOURCE_ARGS = \
  --exclude version.h.in \

DXVK_LOW_LATENCY_MESON_ARGS = -Db_ndebug=true --force-fallback-for=libdisplay-info
DXVK_LOW_LATENCY_i386_MESON_ARGS = --bindir=$(DXVK_LOW_LATENCY_i386_DST)/lib/wine/dxvk-low-latency/i386-windows
DXVK_LOW_LATENCY_x86_64_MESON_ARGS = --bindir=$(DXVK_LOW_LATENCY_x86_64_DST)/lib/wine/dxvk-low-latency/x86_64-windows
DXVK_LOW_LATENCY_arm64ec_MESON_ARGS = --bindir=$(DXVK_LOW_LATENCY_arm64ec_DST)/lib/wine/dxvk-low-latency/aarch64-windows
DXVK_LOW_LATENCY_HOST_DEPENDS = glslang

DXVK_LOW_LATENCY_i386_CFLAGS = -O3 -mno-avx $(i386_SANITY_FLAGS)
DXVK_LOW_LATENCY_x86_64_CFLAGS = -O3 -mno-avx
DXVK_LOW_LATENCY_CPPFLAGS = -msse -msse2
DXVK_LOW_LATENCY_LDFLAGS = -static -static-libgcc -static-libstdc++

$(eval $(call rules-source,dxvk-low-latency,$(SRCDIR)/extras/dxvk-low-latency))
$(eval $(call rules-meson,dxvk-low-latency,i386,windows))
$(eval $(call rules-meson,dxvk-low-latency,x86_64,windows))
$(eval $(call rules-meson,dxvk-low-latency,arm64ec,windows))

$(OBJ)/.dxvk-low-latency-post-source: patches-source
	$(foreach p,$(shell find $(PATCHES_SRC)/extras/dxvk-low-latency/ -name "*.patch" | sort),patch -d $(DXVK_LOW_LATENCY_SRC) -Np1 -i $(p) &&) true
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/extras//dxvk-low-latency describe --always --abbrev=15 --dirty=0)#' \
	    $(SRCDIR)/extras/dxvk-low-latency/version.h.in > $(DXVK_LOW_LATENCY_SRC)/version.h.in
	mkdir -p $(DST_LIBDIR)/wine/dxvk-low-latency
	rm -rf $(DST_LIBDIR)/wine/dxvk-low-latency/version
	echo "$(shell git -C $(SRCDIR) submodule status -- extras/dxvk-low-latency)" > $(DST_LIBDIR)/wine/dxvk-low-latency/version
	touch $@

default_pfx: dxvk-low-latency

endif # WITHOUT_EXTRAS
