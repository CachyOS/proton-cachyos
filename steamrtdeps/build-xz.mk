##
## xz
##

XZ_CONFIGURE_ARGS := \
	--enable-shared \
	--disable-static \
	--disable-xz \
	--disable-xzdec \
	--disable-lzmadec \
	--disable-lzmainfo \
	--disable-lzma-links \
	--disable-scripts \
	--disable-doc \
	--disable-doxygen \
	--disable-nls

$(eval $(call rules-source,xz,$(SRCDIR)/steamrtdeps/xz))
$(eval $(call rules-configure,xz,i386,unix))

$(OBJ)/.xz-post-source:
	cd "$(XZ_SRC)" && autoreconf -fiv
	touch $@

XZ_DEPENDENCY := xz
