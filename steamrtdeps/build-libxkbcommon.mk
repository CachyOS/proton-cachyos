##
## xkbcommon
##

LIBXKBCOMMON_MESON_ARGS := \
	-Denable-xkbregistry=true \
	-Denable-docs=false \
	-Denable-x11=false \
	-Denable-bash-completion=false \
	-Denable-wayland=false

LIBXKBCOMMON_DEPENDS = libxml2

$(eval $(call rules-source,libxkbcommon,$(SRCDIR)/steamrtdeps/libxkbcommon))
$(eval $(call rules-meson,libxkbcommon,i386,unix))
$(eval $(call rules-meson,libxkbcommon,x86_64,unix))
$(eval $(call rules-meson,libxkbcommon,aarch64,unix))

LIBXKBCOMMON_DEPENDENCY := libxkbcommon
