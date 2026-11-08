##
## libpcap
##

LIBPCAP_CONFIGURE_ARGS := \
	--enable-shared \
	--disable-static \
	--disable-usb \
	--disable-netmap \
	--disable-bluetooth \
	--disable-dbus \
	--disable-rdma \
	--with-pcap=linux \
	--without-libnl

$(eval $(call rules-source,libpcap,$(SRCDIR)/steamrtdeps/libpcap))
$(eval $(call rules-configure,libpcap,i386,unix))
$(eval $(call rules-configure,libpcap,x86_64,unix))
$(eval $(call rules-configure,libpcap,aarch64,unix))

$(OBJ)/.libpcap-post-source:
	cd "$(LIBPCAP_SRC)" && autoreconf -fiv
	touch $@

LIBPCAP_DEPENDENCY := libpcap
