##
## libxml2
##

LIBXML2_MESON_ARGS := \
	-Ddocs=disabled \
	-Dicu=disabled \
	-Dlegacy=enabled \
	-Dpython=disabled

$(eval $(call rules-source,libxml2,$(SRCDIR)/steamrtdeps/libxml2))
$(eval $(call rules-meson,libxml2,i386,unix))
$(eval $(call rules-meson,libxml2,x86_64,unix))
$(eval $(call rules-meson,libxml2,aarch64,unix))

LIBXML2_DEPENDENCY := libxml2
