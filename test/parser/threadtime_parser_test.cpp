#include <gtest/gtest.h>
#include "parser/threadtime_parser.h"

using namespace locq;

TEST(ThreadtimeParser, instance) {
  ThreadtimeParser *ttparser = new ThreadtimeParser();
  ASSERT_EQ(true, ttparser != NULL);
  delete ttparser;
}
