cmake_minimum_required(VERSION 2.8)

project(locq)

add_definitions(-DVERSION="0.0.1")

include_directories(
  include
)

if(CMAKE_VERSION VERSION_LESS "2.8.12")
    function(add_compile_options)
        add_definitions(${ARGN})
    endfunction(add_compile_options)
endif()

add_compile_options(-std=c++11)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME locqtest COMMAND locqtest)
