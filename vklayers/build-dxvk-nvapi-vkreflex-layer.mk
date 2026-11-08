##
## dxvk-nvapi-vkreflex-layer
##

ifeq ($(findstring dxvk-nvapi-vkreflex-layer,$(WITHOUT_VKLAYERS)),)

DXVK_NVAPI_VKREFLEX_LAYER_SOURCE_ARGS = \
  --exclude version.h.in \

DXVK_NVAPI_VKREFLEX_LAYER_MESON_ARGS = -Dabsolute_library_path=false

DXVK_NVAPI_VKREFLEX_LAYER_x86_64_CXXFLAGS = -std=c++20
DXVK_NVAPI_VKREFLEX_LAYER_aarch64_CXXFLAGS = -std=c++20

$(eval $(call rules-source,dxvk-nvapi-vkreflex-layer,$(SRCDIR)/dxvk-nvapi/layer))
$(eval $(call rules-meson,dxvk-nvapi-vkreflex-layer,x86_64,unix))
$(eval $(call rules-meson,dxvk-nvapi-vkreflex-layer,aarch64,unix))

$(OBJ)/.dxvk-nvapi-vkreflex-layer-post-source: patches-source dxvk-nvapi-source
	$(foreach p,$(shell find $(PATCHES_SRC)/vklayers/dxvk-nvapi-vkreflex-layer/ -name "*.patch" | sort),patch -d $(DXVK_NVAPI_VKREFLEX_LAYER_SRC) -Np2 -i $(p) &&) true
	sed -re 's#@VCS_TAG@#$(shell git -C $(SRCDIR)/dxvk-nvapi describe --always --abbrev=15 --dirty=0)#' \
	    $(SRCDIR)/dxvk-nvapi/version.h.in > $(DXVK_NVAPI_VKREFLEX_LAYER_SRC)/version.h.in
	cp -a $(SRCDIR)/dxvk-nvapi/config.h.in $(DXVK_NVAPI_VKREFLEX_LAYER_SRC)/config.h.in
	mkdir -p $(DXVK_NVAPI_VKREFLEX_LAYER_SRC)/external/
	rsync -arx $(DXVK_NVAPI_SRC)/external/Vulkan-Headers/ $(DXVK_NVAPI_VKREFLEX_LAYER_SRC)/external/Vulkan-Headers/
	rsync -arx $(DXVK_NVAPI_SRC)/external/vkroots/ $(DXVK_NVAPI_VKREFLEX_LAYER_SRC)/external/vkroots/
	touch $@

$(OBJ)/.dxvk-nvapi-vkreflex-layer-x86_64-post-build:
	mkdir -p $(DST_DIR)/share/dxvk-nvapi-vkreflex-layer/implicit_layer.d/
	cp -a $(DXVK_NVAPI_VKREFLEX_LAYER_x86_64_DST)/share/vulkan/implicit_layer.d/VkLayer_DXVK_NVAPI_reflex.json $(DST_DIR)/share/dxvk-nvapi-vkreflex-layer/implicit_layer.d/
	touch $@

$(OBJ)/.dxvk-nvapi-vkreflex-layer-aarch64-post-build:
	mkdir -p $(DST_DIR)/share/dxvk-nvapi-vkreflex-layer/implicit_layer.d/
	cp -a $(DXVK_NVAPI_VKREFLEX_LAYER_aarch64_DST)/share/vulkan/implicit_layer.d/VkLayer_DXVK_NVAPI_reflex.json $(DST_DIR)/share/dxvk-nvapi-vkreflex-layer/implicit_layer.d/
	touch $@

all-dist: dxvk-nvapi-vkreflex-layer

endif # WITHOUT_VKLAYERS
