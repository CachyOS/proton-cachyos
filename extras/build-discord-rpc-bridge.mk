##
## discord-rpc-bridge
##

ifeq ($(findstring discord-rpc-bridge,$(WITHOUT_EXTRAS)),)

$(eval $(call rules-source,discord-rpc-bridge,$(SRCDIR)/extras/discord-rpc-bridge))
$(eval $(call create-rules-common,discord-rpc-bridge,DISCORD_RPC_BRIDGE,x86_64,unix))
$(eval $(call create-rules-common,discord-rpc-bridge,DISCORD_RPC_BRIDGE,aarch64,unix))

$(OBJ)/.discord-rpc-bridge-post-source: patches-source
	$(foreach p,$(shell find $(PATCHES_SRC)/extras/discord-rpc-bridge/ -name "*.patch" | sort),patch -d $(DISCORD_RPC_BRIDGE_SRC) -Np1 -i $(p) &&) true
	touch $@

$(OBJ)/.discord-rpc-bridge-x86_64-build:
	@echo ":: building discord-rpc-bridge-x86_64..." >&2
	rsync -arx "$(DISCORD_RPC_BRIDGE_SRC)/" "$(DISCORD_RPC_BRIDGE_x86_64_OBJ)/"
	env $(DISCORD_RPC_BRIDGE_x86_64_ENV) \
	    $(MAKE) -C "$(DISCORD_RPC_BRIDGE_x86_64_OBJ)" build
	touch $@

$(OBJ)/.discord-rpc-bridge-x86_64-post-build:
	mkdir -p $(DISCORD_RPC_BRIDGE_x86_64_DST)/lib/wine/discord-rpc-bridge
	$(call install-strip,$(DISCORD_RPC_BRIDGE_x86_64_OBJ)/build/bridge.exe,$(DISCORD_RPC_BRIDGE_x86_64_DST)/lib/wine/discord-rpc-bridge)
	touch $@

$(OBJ)/.discord-rpc-bridge-x86_64-dist:
	mkdir -p $(DST_DIR)/lib/wine/discord-rpc-bridge
	cp -a $(DISCORD_RPC_BRIDGE_x86_64_DST)/lib/wine/discord-rpc-bridge/bridge.exe $(DST_DIR)/lib/wine/discord-rpc-bridge/
	touch $@

$(OBJ)/.discord-rpc-bridge-aarch64-build:
	touch $@

$(OBJ)/.discord-rpc-bridge-aarch64-post-build:
	touch $@

$(OBJ)/.discord-rpc-bridge-aarch64-dist:
	touch $@

default_pfx: discord-rpc-bridge

endif # WITHOUT_EXTRAS
