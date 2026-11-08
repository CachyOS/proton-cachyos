##
## steam-audio
##

ifeq ($(findstring steam-audio,$(WITHOUT_STEAM_AUDIO)),)

##
## flatbuffers
##

STEAM_AUDIO_FLATBUFFERS_CMAKE_ARGS = \
  -DFLATBUFFERS_BUILD_FLATLIB=FALSE \
  -DFLATBUFFERS_BUILD_FLATHASH=FALSE \
  -DFLATBUFFERS_BUILD_TESTS=FALSE

$(eval $(call rules-source,steam-audio-flatbuffers,$(SRCDIR)/steam-audio/flatbuffers))
$(eval $(call rules-cmake,steam-audio-flatbuffers,i386,unix))
$(eval $(call rules-cmake,steam-audio-flatbuffers,x86_64,unix))
$(eval $(call rules-cmake,steam-audio-flatbuffers,aarch64,unix))

##
## pffft
##

STEAM_AUDIO_PFFFT_CMAKE_ARGS = \
  -DPFFFT_USE_TYPE_DOUBLE=OFF \
  -DPFFFT_USE_FFTPACK=OFF \
  -DPFFFT_USE_BENCH_GREEN=OFF \
  -DPFFFT_USE_BENCH_KISS=OFF \
  -DPFFFT_USE_BENCH_POCKET=OFF

STEAM_AUDIO_PFFFT_CFLAGS = -fPIC

$(eval $(call rules-source,steam-audio-pffft,$(SRCDIR)/steam-audio/pffft))
$(eval $(call rules-cmake,steam-audio-pffft,i386,unix))
$(eval $(call rules-cmake,steam-audio-pffft,x86_64,unix))
$(eval $(call rules-cmake,steam-audio-pffft,aarch64,unix))

##
## zlib
##

STEAM_AUDIO_ZLIB_CMAKE_ARGS = \
  -DZLIB_BUILD_EXAMPLES=FALSE \
  -DBUILD_TESTS=FALSE

$(eval $(call rules-source,steam-audio-zlib,$(SRCDIR)/steam-audio/zlib))
$(eval $(call rules-cmake,steam-audio-zlib,i386,unix))
$(eval $(call rules-cmake,steam-audio-zlib,x86_64,unix))
$(eval $(call rules-cmake,steam-audio-zlib,aarch64,unix))

$(OBJ)/.zlib-post-source: steam-audio-source
	patch -d $(STEAM_AUDIO_ZLIB_SRC) -Np1 -i $(STEAM_AUDIO_SRC)/build/zlib.patch
	touch $@

##
## libmysofa
##

STEAM_AUDIO_LIBMYSOFA_CMAKE_ARGS = \
  -DBUILD_SHARED_LIBS=FALSE \
  -DBUILD_TESTS=FALSE \

STEAM_AUDIO_LIBMYSOFA_i386_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_i386_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_i386_DST)/include

STEAM_AUDIO_LIBMYSOFA_x86_64_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_x86_64_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_x86_64_DST)/include

STEAM_AUDIO_LIBMYSOFA_aarch64_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_aarch64_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_aarch64_DST)/include

STEAM_AUDIO_LIBMYSOFA_DEPENDS = steam-audio-zlib

STEAM_AUDIO_LIBMYSOFA_CFLAGS = -fPIC

$(eval $(call rules-source,steam-audio-libmysofa,$(SRCDIR)/steam-audio/libmysofa))
$(eval $(call rules-cmake,steam-audio-libmysofa,i386,unix))
$(eval $(call rules-cmake,steam-audio-libmysofa,x86_64,unix))
$(eval $(call rules-cmake,steam-audio-libmysofa,aarch64,unix))

##
## steam-audio
##

STEAM_AUDIO_CMAKE_ARGS = \
  -DBUILD_SHARED_LIBS=ON \
  -DSTEAMAUDIO_BUILD_TESTS=OFF \
  -DSTEAMAUDIO_BUILD_ITESTS=OFF \
  -DSTEAMAUDIO_BUILD_BENCHMARKS=OFF \
  -DSTEAMAUDIO_BUILD_SAMPLES=OFF \
  -DSTEAMAUDIO_BUILD_DOCS=OFF \
  -DSTEAMAUDIO_ENABLE_AVX=OFF \
  -DSTEAMAUDIO_ENABLE_IPP=OFF \
  -DSTEAMAUDIO_ENABLE_EMBREE=OFF \
  -DCMAKE_BUILD_TYPE=release

STEAM_AUDIO_i386_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_i386_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_i386_DST)/include

STEAM_AUDIO_x86_64_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_x86_64_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_x86_64_DST)/include

STEAM_AUDIO_aarch64_CMAKE_ARGS = \
  -DZLIB_ROOT=$(STEAM_AUDIO_ZLIB_aarch64_DST)/lib/libz.a \
  -DZLIB_INCLUDE_DIR=$(STEAM_AUDIO_ZLIB_aarch64_DST)/include

STEAM_AUDIO_DEPENDS = steam-audio-flatbuffers steam-audio-pffft steam-audio-zlib steam-audio-libmysofa

$(eval $(call rules-source,steam-audio,$(SRCDIR)/steam-audio/steam-audio/core))
$(eval $(call rules-cmake,steam-audio,i386,unix))
$(eval $(call rules-cmake,steam-audio,x86_64,unix))
$(eval $(call rules-cmake,steam-audio,aarch64,unix))

$(OBJ)/.steam-audio-i386-post-build:
	mkdir -p $(STEAM_AUDIO_i386_DST)/lib/$(i386-unix_LIBDIR)
	mv $(STEAM_AUDIO_i386_DST)/lib/linux-x86/libphonon.so  $(STEAM_AUDIO_i386_DST)/lib/$(i386-unix_LIBDIR)
	touch $@

$(OBJ)/.steam-audio-x86_64-post-build:
	mkdir -p $(STEAM_AUDIO_x86_64_DST)/lib/$(x86_64-unix_LIBDIR)
	mv $(STEAM_AUDIO_x86_64_DST)/lib/linux-x64/libphonon.so  $(STEAM_AUDIO_x86_64_DST)/lib/$(x86_64-unix_LIBDIR)
	touch $@

$(OBJ)/.steam-audio-aarch64-post-build:
	mkdir -p $(STEAM_AUDIO_aarch64_DST)/lib/$(aarch64-unix_LIBDIR)
	mv $(STEAM_AUDIO_aarch64_DST)/lib/linux-arm64/libphonon.so  $(STEAM_AUDIO_aarch64_DST)/lib/$(aarch64-unix_LIBDIR)
	touch $@

steam-audio-distclean::
	rm -rf $(OBJ)/fmod
	rm -rf $(OBJ)/unity
	rm -rf $(OBJ)/unreal
	rm -rf $(OBJ)/wwise

distclean: steam-audio-distclean

STEAM_AUDIO_DEPENDENCY := steam-audio

endif # WITHOUT_STEAM_AUDIO
