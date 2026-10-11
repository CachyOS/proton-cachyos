##
## zluda
##

ifeq ($(findstring zluda,$(WITHOUT_ZLUDA_LIBS)),)

ZLUDA_VER := v7-preview.15
ZLUDA_SHA := 86ec0a9
ZLUDA_TARBALL := zluda-windows-$(ZLUDA_SHA).zip
DIST_ZLUDA_DIR := $(DST_DIR)/lib/wine/zluda-libs/zluda
DIST_ZLUDA := $(OBJ)/.zluda-dist
ZLUDA_TARBALL_URL := https://github.com/vosen/ZLUDA/releases/download/$(ZLUDA_VER)/$(ZLUDA_TARBALL)

$(SRC)/contrib/$(ZLUDA_TARBALL):
	mkdir -p $(dir $@)
	wget --no-use-server-timestamps -O $@ $(ZLUDA_TARBALL_URL) || (rm $@; false)

$(DIST_ZLUDA): $(SRC)/contrib/$(ZLUDA_TARBALL)
	rm -rf $(DIST_ZLUDA_DIR)
	mkdir -p $(DIST_ZLUDA_DIR)
	unzip $< -d $(DIST_ZLUDA_DIR)
	mkdir -p $(DIST_ZLUDA_DIR)/x86_64-windows
	mv $(DIST_ZLUDA_DIR)/zluda/*.exe $(DIST_ZLUDA_DIR)/zluda/*.dll $(DIST_ZLUDA_DIR)/x86_64-windows
	mv $(DIST_ZLUDA_DIR)/zluda//32 $(DIST_ZLUDA_DIR)/i386-windows
	rm -rf $(DIST_ZLUDA_DIR)/zluda
	touch $@

all-dist: $(DIST_ZLUDA)

zluda-distclean::
	rm -rf $(OBJ)/.zluda-dist

distclean: zluda-distclean

endif # WITHOUT_ZLUDA_LIBS
