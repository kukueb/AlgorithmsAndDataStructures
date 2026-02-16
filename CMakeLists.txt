cmake_minimum_required(VERSION 3.16)

project(Algorithms)

add_executable(run
  src/main.cpp
  src/list.hpp
  src/list.cpp
  ${SOURCES}
)
