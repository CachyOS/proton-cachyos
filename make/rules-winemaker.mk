# parameters:
#   $(1): lowercase package name
#   $(2): uppercase package name
#   $(3): build target arch
#   $(4): module name (with extension)
#
define create-rules-winemaker
$(call create-rules-common,$(1),$(2),$(3),unix)
ifneq ($(findstring $(3)-unix,$(ARCHS)),)

$(2)_$(3)_OBJ := $$($(2)_$(3)_OBJ)/$(4)

$$(OBJ)/.$(1)-$(3)-configure: $$(OBJ)/.wine-$$(HOST_ARCH)-tools
	@echo ":: configuring $(1)-$(3)..." >&2
	rsync -arx "$$($(2)_SRC)/" "$$($(2)_$(3)_OBJ)/"
	cd "$$($(2)_$(3)_OBJ)" && env $$($(2)_$(3)_ENV) \
	$$(WINE_$$(HOST_ARCH)_OBJ)/tools/winemaker/winemaker \
	    --nosource-fix \
	    --nolower-include \
	    --nodlls \
	    --nomsvcrt \
	    "-I$$(WINE_SRC)/include" \
	    "-I$$(WINE_SRC)/include/wine" \
	    "-I$$(WINE_$(3)_DST)/include/wine" \
	    $(patsubst %.dll,--dll,$(patsubst %.exe,--guiexe,$(4))) \
	    $$($(3)_WINEMAKER_ARGS) \
	    $$($(2)_WINEMAKER_ARGS) \
	    $$($(2)_$(3)_WINEMAKER_ARGS) \
	    .
	sed -re 's@_LDFLAGS=@_LDFLAGS= $$$$(LDFLAGS) @' -i "$$($(2)_$(3)_OBJ)/Makefile"
	touch $$@

$$(OBJ)/.$(1)-$(3)-build:
	@echo ":: building $(1)-$(3)..." >&2
	rsync -arx "$$($(2)_SRC)/" "$$($(2)_$(3)_OBJ)/"
	env $$($(2)_$(3)_ENV) \
	$$(MAKE) -j$$(SUBJOBS) -C "$$($(2)_$(3)_OBJ)" LIBRARIES="$$($(2)_LDFLAGS)"
	cd "$$($(2)_$(3)_OBJ)" && touch "$(basename $(4)).spec" && env $$($(2)_$(3)_ENV) \
	$$(WINE_$$(HOST_ARCH)_OBJ)/tools/winebuild/winebuild --$(lastword $(subst ., ,$(4))) \
	    --fake-module -E "$(basename $(4)).spec" -o "$(4).fake"
	mkdir -p $$($(2)_$(3)_LIBDIR)/wine/$(3)-unix
	cp -a $$($(2)_$(3)_OBJ)/$(4).so $$($(2)_$(3)_LIBDIR)/wine/$(3)-unix/
	mkdir -p $$($(2)_$(3)_LIBDIR)/wine/$(3)-windows
	cp -a $$($(2)_$(3)_OBJ)/$(4).fake $$($(2)_$(3)_LIBDIR)/wine/$(3)-windows/$(4)
	touch $$@

endif
endef

i386_WINEMAKER_ARGS := --wine32
x86_64_WINEMAKER_ARGS :=

rules-winemaker = $(call create-rules-winemaker,$(1),$(call toupper,$(1)),$(2),$(3))
