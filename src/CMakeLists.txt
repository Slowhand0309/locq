cmake_minimum_required(VERSION 2.8)

project(locq)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
)

add_compile_options(-std=c++11)

set(locq_src
  utils.cpp
  option.cpp
  session.cpp
  view/view.cpp
  view/query_view.cpp
  parser/parser.cpp
  parser/brief_parser.cpp
  parser/threadtime_parser.cpp
  executor.cpp
)
add_library(locq_lib STATIC
    ${locq_src}
)

add_executable(locq
  main.cpp
)
target_link_libraries(locq locq_lib)
