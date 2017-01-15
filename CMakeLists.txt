cmake_minimum_required(VERSION 2.8)

project(locq)

include_directories(
  include
)

add_compile_options(-std=c++11)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME locqtest COMMAND locqtest)
