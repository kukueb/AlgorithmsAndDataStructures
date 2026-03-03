cmake_minimum_required(VERSION 3.16)

project(Lists2)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
  src/main.cpp
  src/list/list.cpp
  src/list/list.hpp
  src/utils/utils.cpp
  src/utils/utils.hpp
)

add_executable(
  run
  ${SOURCES}
)
