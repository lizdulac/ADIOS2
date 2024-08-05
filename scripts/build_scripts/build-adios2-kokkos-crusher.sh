#!/bin/bash
# shellcheck disable=SC2191

module load rocm/5.4.0
#module load gcc/11.2.0
module load gcc-native
module load cmake/3.23.2
module load craype-accel-amd-gfx90a

######## User Configurations ########
Kokkos_HOME=$HOME/Coeus-Hackathon/kokkos/
StateDiff_HOME=$HOME/Coeus-Hackathon/state-diff/
ADIOS2_HOME=$(pwd)
BUILD_DIR=${ADIOS2_HOME}/build-kokkos-crusher
INSTALL_DIR=${ADIOS2_HOME}/install-kokkos-crusher

num_build_procs=4

######## StateDiff ########
mkdir -p "${BUILD_DIR}/state-diff"
rm -f "${BUILD_DIR}/state-diff/CMakeCache.txt"
rm -rf "${BUILD_DIR}/state-diff/CMakeFiles"

ARGS=(
    -D CMAKE_BUILD_TYPE=RelWithDebInfo
    -D CMAKE_INSTALL_PREFIX="${INSTALL_DIR}"
	-D CMAKE_CXX_COMPILER=hipcc

    -D CMAKE_CXX_STANDARD=17
    -D CMAKE_CXX_EXTENSIONS=OFF
    -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE
	-D BUILD_SHARED_LIBS=ON
)
cmake "${ARGS[@]}" -S "${StateDiff_HOME}" -B "${BUILD_DIR}/state-diff"
cmake --build "${BUILD_DIR}/state-diff" -j${num_build_procs}
cmake --install "${BUILD_DIR}/state-diff"

######## Kokkos ########
mkdir -p "${BUILD_DIR}/kokkos"
rm -f "${BUILD_DIR}/kokkos/CMakeCache.txt"
rm -rf "${BUILD_DIR}/kokkos/CMakeFiles"

ARGS=(
    -D CMAKE_BUILD_TYPE=RelWithDebInfo
    -D CMAKE_INSTALL_PREFIX="${INSTALL_DIR}"
	-D CMAKE_CXX_COMPILER=hipcc

    -D Kokkos_ENABLE_SERIAL=ON
    -D Kokkos_ARCH_ZEN3=ON
    -D Kokkos_ENABLE_HIP=ON
    -D Kokkos_ARCH_VEGA90A=ON

    -D CMAKE_CXX_STANDARD=17
    -D CMAKE_CXX_EXTENSIONS=OFF
    -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE
	-D BUILD_SHARED_LIBS=ON
)
cmake "${ARGS[@]}" -S "${Kokkos_HOME}" -B "${BUILD_DIR}/kokkos"
cmake --build "${BUILD_DIR}/kokkos" -j${num_build_procs}
cmake --install "${BUILD_DIR}/kokkos"

######## ADIOS2 ########
mkdir -p "${BUILD_DIR}/adios2"
rm -f "${BUILD_DIR}/adios2/CMakeCache.txt"
rm -rf "${BUILD_DIR}/adios2/CMakeFiles"

ARGS_ADIOS=(
    -D CMAKE_INSTALL_PREFIX="${INSTALL_DIR}"
    -D CMAKE_CXX_COMPILER=g++
    -D CMAKE_C_COMPILER=gcc

    -D ADIOS2_USE_Kokkos=ON
    -D Kokkos_ROOT="${INSTALL_DIR}"
    -D StateDiff_ROOT="${INSTALL_DIR}"

    -D BUILD_TESTING=ON
    -D ADIOS2_USE_Derived_Variable=ON
    -D ADIOS2_USE_SST=OFF
    #-D StateDiff_DIR=/ccs/home/ldulac/Coeus-Hackathon/state-diff/build/install/lib/cmake/StateDiff
    #-D StateDiff_ROOT=/ccs/home/ldulac/Coeus-Hackathon/state-diff/build/install

    -D CMAKE_POSITION_INDEPENDENT_CODE=TRUE
    -D BUILD_SHARED_LIBS=ON
)
cmake "${ARGS_ADIOS[@]}" -S "${ADIOS2_HOME}" -B "${BUILD_DIR}"/adios2
cmake --build "${BUILD_DIR}/adios2" -j${num_build_procs}
cmake --install "${BUILD_DIR}/adios2"
