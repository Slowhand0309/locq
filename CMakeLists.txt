cmake_minimum_required(VERSION 2.8)

project(locq)

include_directories(
  include
)

add_executable(locq
  src/main.cpp
  src/ansi.cpp
)
