##
## hipwine
##

ifeq ($(findstring hipwine,$(WITHOUT_ZLUDA_LIBS)),)

HIPWINE_x86_64_MESON_ARGS = \
  --cross-file=$(HIPWINE_SRC)/build-wine64.txt \
  --libdir=lib/wine/zluda-libs/hipwine/x86_64-windows

HIPWINE_DEPENDS = wine
HIPWINE_HOST_DEPENDS = wine

$(eval $(call rules-source,hipwine,$(SRCDIR)/zluda-libs/hipwine))
$(eval $(call rules-meson-wine,hipwine,x86_64,windows))

$(OBJ)/.hipwine-post-source: patches-source $(OBJ)/.wine-wine-requests
	$(foreach p,$(shell find $(PATCHES_SRC)/zluda-libs/hipwine/ -name "*.patch" | sort),patch -d $(HIPWINE_SRC) -Np1 -i $(p) &&) true
	$(foreach i,$(shell find $(HIPWINE_SRC)/include/wine -type f | sort),cp $(WINE_SRC)/include/wine/$(notdir $(i)) $(i) &&) true
	mkdir -p $(DST_LIBDIR)/wine/zluda-libs/hipwine
	rm -rf $(DST_LIBDIR)/wine/zluda-libs/hipwine/version
	echo "$(shell git -C $(SRCDIR) submodule status -- zluda-libs/hipwine)" > $(DST_LIBDIR)/wine/zluda-libs/hipwine/version
	touch $@

default_pfx: hipwine

endif # WITHOUT_ZLUDA_LIBS
