##
## dxvk-sarek
##

ifeq ($(findstring dxvk-sarek,$(WITHOUT_EXTRAS)),)

# wine builds DLLs with the same names, we need to differentiate the timestamps
DXVK_SAREK_i386_SOURCE_DATE_EPOCH := $(shell expr $(i386_SOURCE_DATE_EPOCH) - 1)
DXVK_SAREK_x86_64_SOURCE_DATE_EPOCH := $(shell expr $(x86_64_SOURCE_DATE_EPOCH) - 1)
DXVK_SAREK_arm64ec_SOURCE_DATE_EPOCH := $(shell expr $(arm64ec_SOURCE_DATE_EPOCH) - 1)

DXVK_SAREK_SOURCE_ARGS = \
  --exclude version.h.in \

DXVK_SAREK_MESON_ARGS = -Db_ndebug=true --force-fallback-for=libdisplay-info
DXVK_SAREK_i386_MESON_ARGS = --bindir=$(DXVK_SAREK_i386_DST)/lib/wine/dxvk-sarek/i386-windows
DXVK_SAREK_x86_64_MESON_ARGS = --bindir=$(DXVK_SAREK_x86_64_DST)/lib/wine/dxvk-sarek/x86_64-windows
DXVK_SAREK_arm64ec_MESON_ARGS = --bindir=$(DXVK_SAREK_arm64ec_DST)/lib/wine/dxvk-sarek/aarch64-windows
DXVK_SAREK_HOST_DEPENDS = glslang

DXVK_SAREK_i386_CFLAGS = -O3 -mno-avx $(i386_SANITY_FLAGS)
DXVK_SAREK_x86_64_CFLAGS = -O3 -mno-avx
DXVK_SAREK_CPPFLAGS = -msse -msse2
DXVK_SAREK_LDFLAGS = -static -static-libgcc -static-libstdc++

$(eval $(call rules-source,dxvk-sarek,$(SRCDIR)/extras/dxvk-sarek))
$(eval $(call rules-meson,dxvk-sarek,i386,windows))
$(eval $(call rules-meson,dxvk-sarek,x86_64,windows))
$(eval $(call rules-meson,dxvk-sarek,arm64ec,windows))

$(OBJ)/.dxvk-sarek-post-source:
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/extras/dxvk-sarek describe --always --abbrev=15 --dirty=0)#' \
	    $(SRCDIR)/extras/dxvk-sarek/version.h.in > $(DXVK_SAREK_SRC)/version.h.in
	mkdir -p $(DST_LIBDIR)/wine/dxvk-sarek
	rm -rf $(DST_LIBDIR)/wine/dxvk-sarek/version
	echo "$(shell git -C $(SRCDIR) submodule status -- extras/dxvk-sarek)" > $(DST_LIBDIR)/wine/dxvk-sarek/version
	touch $@

default_pfx: dxvk-sarek

endif # WITHOUT_EXTRAS
