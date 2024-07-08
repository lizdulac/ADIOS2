#------------------------------------------------------------------------------#
# Distributed under the OSI-approved Apache License, Version 2.0.  See
# accompanying file Copyright.txt for details.
#------------------------------------------------------------------------------#

message("****HIIII in derived kokkos subroutine!")

if (NOT DEFINED Kokkos_CXX_COMPILER)
  message(FATAL_ERROR "ADIOS: Kokkos module requires the Kokkos_CXX_COMPILER variable")
endif()

# CXX Compiler settings only in for this subdir
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "../../${Kokkos_CXX_COMPILER}")
target_sources(adios2_core PRIVATE
  ../../core/VariableDerived.cpp
  ../../toolkit/derived/Expression.cpp
  ../../toolkit/derived/Function.cpp
  ../../toolkit/derived/Function.tcc)

find_package(BISON "3.8.2")
find_package(FLEX)

if(NOT BISON_FOUND OR NOT FLEX_FOUND)
  include(ADIOSBisonFlexSub)
  SETUP_ADIOS_BISON_FLEX_SUB()
else()
  BISON_TARGET(MyParser
    ../../toolkit/derived/parser/parser.y
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
    COMPILE_FLAGS "-o parser.cpp --header=parser.h"
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/parser.h)
  FLEX_TARGET(MyScanner
    ../../toolkit/derived/parser/lexer.l
    COMPILE_FLAGS "-o lexer.cpp --header-file=lexer.h"
    ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/lexer.h)
  ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)
endif()
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp PROPERTIES COMPILE_FLAGS -Wno-sign-compare)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/parser.cpp PROPERTIES COMPILE_FLAGS -Wno-unused-but-set-variable)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "IntelLLVM")
  SET_SOURCE_FILES_PROPERTIES(${CMAKE_CURRENT_BINARY_DIR}/parser.cpp PROPERTIES COMPILE_FLAGS -Wno-unused-but-set-variable)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  SET_SOURCE_FILES_PROPERTIES(../../toolkit/derived/Expression.cpp ../../toolkit/derived/Function.cpp PROPERTIES COMPILE_FLAGS "/wd4005 /wd4065 /wd4267 -DYY_\
NO_UNISTD_H")
endif()
add_library(adios2_core_derived
  ../../toolkit/derived/parser/pregen-source/lexer.cpp
  ../../toolkit/derived/parser/pregen-source/parser.cpp
  ../../toolkit/derived/state-diff/include/kokkos_murmur3.hpp
  ../../toolkit/derived/parser/ASTDriver.cpp
  ../../toolkit/derived/parser/ASTNode.cpp)
#  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp
#  ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
#  adiosKokkos.h
#  adiosKokkos.cpp
#  pthread)

#add_library(adios2_core_kokkos adiosKokkos.h adiosKokkos.cpp)

set_target_properties(adios2_core_derived PROPERTIES
  VISIBILITY_INLINES_HIDDEN ON
  INCLUDE_DIRECTORIES "$<BUILD_INTERFACE:${ADIOS2_SOURCE_DIR}/source/adios2/toolkit/derived/parser>;$<BUILD_INTERFACE:${ADIOS2_BINARY_DIR}/source/adios2>"
  EXPORT_NAME core_derived
  OUTPUT_NAME adios2${ADIOS2_LIBRARY_SUFFIX}_core_derived
  )

#kokkos_compilation(SOURCE adiosKokkos.cpp)
target_link_libraries(adios2_core_derived PRIVATE Kokkos::kokkos)
message("****HIIII derived kokkos subroutine complete!!")
