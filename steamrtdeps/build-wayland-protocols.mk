##
## wayland-protocols
##

WAYLAND_PROTOCOLS_MESON_ARGS := \
	-Dtests=false

$(eval $(call rules-source,wayland-protocols,$(SRCDIR)/steamrtdeps/wayland-protocols))
$(eval $(call rules-meson,wayland-protocols,i386,unix))
$(eval $(call rules-meson,wayland-protocols,x86_64,unix))
$(eval $(call rules-meson,wayland-protocols,aarch64,unix))

WAYLAND_PROTOCOLS_DEPENDENCY := wayland-protocols
