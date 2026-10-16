##
## rocm-systems
##

ifeq ($(findstring rocm-systems,$(WITHOUT_ZLUDA_LIBS)),)

ROCM_SYSTEMS_ROCPROFILER_CMAKE_ARGS = \
  -Wno-dev \
  -DCMAKE_BUILD_TYPE=Release \
  -DROCPROFILER_REGISTER_BUILD_GLOG=OFF \
  -DROCPROFILER_REGISTER_BUILD_FMT=OFF

ROCM_SYSTEMS_ROCPROFILER_CFLAGS = -DNDEBUG

$(eval $(call rules-source,rocm-systems-rocprofiler,$(SRCDIR)/zluda-libs/rocm-systems/projects/rocprofiler-register))
$(eval $(call rules-cmake,rocm-systems-rocprofiler,x86_64,unix))


ROCM_SYSTEMS_ROCR_CMAKE_ARGS = \
  -Wno-dev \
  -DLLVM_DIR=/opt/rocm/lib/llvm/lib/cmake/llvm \
  -DClang_DIR=/opt/rocm/lib/llvm/lib/cmake/clang \
  -DBUILD_SHARED_LIBS=ON

ROCM_SYSTEMS_ROCR_CFLAGS = -DNDEBUG

ROCM_SYSTEMS_ROCR_DEPENDS = rocm-systems-rocprofiler

$(eval $(call rules-source,rocm-systems-rocr,$(SRCDIR)/zluda-libs/rocm-systems/projects/rocr-runtime))
$(eval $(call rules-cmake,rocm-systems-rocr,x86_64,unix))


ROCM_SYSTEMS_CLR_CMAKE_ARGS = \
  -Wno-dev \
  -DLLVM_ROOT=/opt/rocm/lib/llvm \
  -DClang_ROOT=/opt/rocm/lib/llvm \
  -DHIP_COMMON_DIR=$(ROCM_SYSTEMS_HIP_SRC) \
  -DHIPNV_DIR=$(ROCM_SYSTEMS_HIPOTHER_SRC)/hipnv \
  -DHIP_PLATFORM=amd \
  -DHIP_CATCH_TEST=0 \
  -DCLR_BUILD_HIP=ON \
  -DCLR_BUILD_OCL=OFF

ROCM_SYSTEMS_CLR_CFLAGS = -DNDEBUG

ROCM_SYSTEMS_CLR_DEPENDS = rocm-systems-rocprofiler rocm-systems-rocr

$(eval $(call rules-source,rocm-systems-hip,$(SRCDIR)/zluda-libs/rocm-systems/projects/hip))
$(eval $(call rules-source,rocm-systems-hipother,$(SRCDIR)/zluda-libs/rocm-systems/projects/hipother))
$(eval $(call rules-source,rocm-systems-clr,$(SRCDIR)/zluda-libs/rocm-systems/projects/clr))
$(eval $(call rules-cmake,rocm-systems-clr,x86_64,unix))

$(OBJ)/.rocm-systems-clr-post-source: rocm-systems-hip-source rocm-systems-hipother-source

ROCM_SYSTEMS_CLR_DEPENDENCY := rocm-systems-clr

endif # WITHOUT_ZLUDA_LIBS
