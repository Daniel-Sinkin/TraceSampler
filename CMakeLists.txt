cmake_minimum_required(VERSION 3.20)
project(trace_sampler LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE APP_SOURCES
  CONFIGURE_DEPENDS
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
)

add_executable(app
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${APP_SOURCES}
)

target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp")
  target_precompile_headers(app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp
  )
endif()

target_compile_options(app PRIVATE
  -Wall
  -Wextra
  -Wpedantic
  -Werror
  -Wshadow
  -Wconversion
  -Wsign-conversion
  -Wcast-qual
  -Wcast-align
  -Wformat=2
  -Wundef
  -Wnull-dereference
  -Wnon-virtual-dtor
  -Woverloaded-virtual
  -Wold-style-cast
  -Wzero-as-null-pointer-constant
  -Wdouble-promotion
  -Wimplicit-fallthrough
  -Wreturn-type
)