
# Copyright (c) 2012, 2013 openMVG authors.

# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(openMVG C CXX)

# guard against in-source builds
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed.")
ENDIF()

# ==============================================================================
# Additional cmake find modules
# ==============================================================================
SET(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmakeFindModules)

# ==============================================================================
# Check C++11 support
# ==============================================================================
INCLUDE(CXX11)
check_for_cxx11_compiler(CXX11_COMPILER)
# If a C++11 compiler is available, then set the appropriate flags
IF(CXX11_COMPILER)
  enable_cxx11()
ENDIF(CXX11_COMPILER)

# ==============================================================================
# Include directories
# ==============================================================================
SET(test_INCLUDES
  ./cereal/include
  CACHE PATH "include directories"
)

INCLUDE_DIRECTORIES(./cereal/include)

ADD_EXECUTABLE(main main.cpp)
