##
## speex
##

SPEEX_CONFIGURE_ARGS := \
	--enable-shared \
	--disable-static \
	--disable-binaries \
	--disable-valgrind

SPEEX_DEPENDS = $(SPEEXDSP_DEPENDENCY)

$(eval $(call rules-source,speex,$(SRCDIR)/steamrtdeps/speex))
$(eval $(call rules-configure,speex,i386,unix))

$(OBJ)/.speex-post-source:
	cd "$(SPEEX_SRC)" && autoreconf -fiv
	touch $@

SPEEX_DEPENDENCY := speex
