##
## flac
##

FLAC_CONFIGURE_ARGS := \
	--enable-shared \
	--disable-static \
	--disable-cpplibs \
	--disable-programs \
	--disable-examples \
	--disable-doxygen-docs \
	--disable-valgrind-testing

$(eval $(call rules-source,flac,$(SRCDIR)/steamrtdeps/flac))
$(eval $(call rules-configure,flac,i386,unix))

$(OBJ)/.flac-post-source:
	cd "$(FLAC_SRC)" && ./autogen.sh
	touch $@

FLAC_DEPENDENCY := flac
