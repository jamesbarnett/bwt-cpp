cmake_minimum_required (VERSION 2.6)
project (bwt)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

set(BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(bwt_VERSION_MAJOR 0)
set(bwt__VERSION_MINOR 1)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
 set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
 set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
 if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
   string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
 else()
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
 endif()
endif()

add_executable(bwt src/main.cpp)

install(TARGETS bwt RUNTIME DESTINATION ${BIN_DIR})
