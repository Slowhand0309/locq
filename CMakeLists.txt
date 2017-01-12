cmake_minimum_required(VERSION 2.8)

project(locq)

include_directories(
  include
)

add_compile_options(-std=c++11)

add_executable(locq
  src/utils.cpp
  src/session.cpp
  src/view/view.cpp
  src/view/query_view.cpp
  src/main.cpp
)
