cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE (GTest)

include_directories(
  ${GTEST_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(locqtest
  emitter_test.cpp
  utils_test.cpp
  parser/brief_parser_test.cpp
  parser/process_parser_test.cpp
  parser/threadtime_parser_test.cpp
  parser/regex_parser.cpp
)

target_link_libraries(locqtest
  ${GTEST_BOTH_LIBRARIES}
  locq_lib
)
