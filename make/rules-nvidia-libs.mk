# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): build target arch
#   $(4): build target os
#
define create-rules-nvidia-libs
$(call create-rules-common,$(1),$(2),$(3),$(4))
ifneq ($(findstring $(3)-$(4),$(ARCHS)),)

$(2)_MESON_ARGS = -Db_ndebug=true --buildtype=release --strip

$(2)_$(3)_ENV += \
	PATH="$$(WINE_$(3)_DST)/bin:$$$$PATH"

$$($(2)_SRC)/meson.build: | $$(OBJ)/.$(1)-post-source

$$(OBJ)/.$(1)-$(3)-configure: $$($(2)_SRC)/meson.build meson-source $$(OBJ)/.wine-$(3)-tools
	@echo ":: configuring $(1)-$(3)..." >&2
	rm -rf "$$($(2)_$(3)_OBJ)/meson-private/coredata.dat"

	env $$($(2)_$(3)_ENV) \
	$$(OBJ)/src-meson/meson.py "$$($(2)_$(3)_OBJ)" "$$($(2)_SRC)" \
	      --prefix="$$($(2)_$(3)_DST)" \
	      --buildtype=release \
	      $$($(3)-$(4)_MESON_ARGS) \
	      $$($(2)_MESON_ARGS) \
	      $$($(2)_$(3)_MESON_ARGS) \
	      $$(MESON_STRIP_ARG)

	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	+env $$($(2)_$(3)_ENV) \
	ninja -C "$$($(2)_$(3)_OBJ)" install
	touch $$@
endif
endef

rules-nvidia-libs = $(call create-rules-nvidia-libs,$(1),$(call toupper,$(1)),$(2),$(3))
