##
## d7vk
##

ifeq ($(findstring d7vk,$(WITHOUT_EXTRAS)),)

# wine builds DLLs with the same names, we need to differentiate the timestamps
D7VK_i386_SOURCE_DATE_EPOCH := $(shell expr $(i386_SOURCE_DATE_EPOCH) - 1)

D7VK_SOURCE_ARGS = \
  --exclude version.h.in \

D7VK_MESON_ARGS  = -Db_ndebug=true --force-fallback-for=libdisplay-info
D7VK_MESON_ARGS += -Denable_dxgi=false -Denable_d3d8=false -Denable_d3d10=false -Denable_d3d11=false
D7VK_i386_MESON_ARGS = --bindir=$(D7VK_i386_DST)/lib/wine/d7vk/i386-windows
D7VK_HOST_DEPENDS = glslang

D7VK_i386_CFLAGS = -O3 -mno-avx $(i386_SANITY_FLAGS)
D7VK_CPPFLAGS = -msse -msse2
D7VK_LDFLAGS = -static -static-libgcc -static-libstdc++

$(eval $(call rules-source,d7vk,$(SRCDIR)/extras/d7vk))
$(eval $(call rules-meson,d7vk,i386,windows))

$(OBJ)/.d7vk-post-source:
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/extras/d7vk describe --always --abbrev=15 --dirty=0)#' \
	    $(SRCDIR)/extras/d7vk/version.h.in > $(D7VK_SRC)/version.h.in
	mkdir -p $(DST_LIBDIR)/wine/d7vk
	rm -rf $(DST_LIBDIR)/wine/d7vk/version
	echo "$(shell git -C $(SRCDIR) submodule status -- extras/d7vk)" > $(DST_LIBDIR)/wine/d7vk/version
	touch $@

default_pfx: d7vk

endif # WITHOUT_EXTRAS


