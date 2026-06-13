##
## speexdsp
##

SPEEXDSP_CONFIGURE_ARGS := \
	--enable-shared \
	--disable-static \
	--disable-examples

$(eval $(call rules-source,speexdsp,$(SRCDIR)/steamrtdeps/speexdsp))
$(eval $(call rules-configure,speexdsp,i386,unix))

$(OBJ)/.speexdsp-post-source:
	cd "$(SPEEXDSP_SRC)" && autoreconf -fiv
	touch $@

SPEEXDSP_DEPENDENCY := speexdsp
