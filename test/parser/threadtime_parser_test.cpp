#include <gtest/gtest.h>
#include "parser/threadtime_parser.h"

using namespace locq;

//#define DEBUG

/**
 * Test for create instance.
 */
TEST(ThreadtimeParser, instance) {
  ThreadtimeParser *ttparser = new ThreadtimeParser();
  ASSERT_EQ(true, ttparser != NULL);
  delete ttparser;
}

/**
 * Test for normal log message.
 */
TEST(ThreadtimeParser, parse_normal) {
  string testlog = "01-15 21:01:12.211  1556  1962 I TAG: message";
  element_t element;

  ThreadtimeParser *ttparser = new ThreadtimeParser();
  int ret = ttparser->parse(testlog, element);

#ifdef DEBUG
  cout << "[" << element.date << "]" << endl;
  cout << "[" << element.time << "]" << endl;
  cout << "[" << element.pid << "]" << endl;
  cout << "[" << element.tid << "]" << endl;
  cout << "[" << element.priority << "]" << endl;
  cout << "[" << element.tag << "]" << endl;
  cout << "[" << element.message << "]" << endl;
  cout << ret << endl;
#endif

  EXPECT_STREQ("01-15", element.date.c_str());
  EXPECT_STREQ("21:01:12.211", element.time.c_str());
  EXPECT_EQ(1556, element.pid);
  EXPECT_EQ(1962, element.tid);
  EXPECT_STREQ("I", element.priority.c_str());
  EXPECT_STREQ("TAG:", element.tag.c_str());
  EXPECT_STREQ("message", element.message.c_str());
  EXPECT_EQ(1, ret);

  delete ttparser;
}

/**
 * Test for included space log message.
 */
TEST(ThreadtimeParser, parse_included_space) {
  string testlog = "01-15 21:30:21.080  1556  1572 D ProcessStatsService: Prepared write state in 1ms";
  element_t element;

  ThreadtimeParser *ttparser = new ThreadtimeParser();
  int ret = ttparser->parse(testlog, element);

#ifdef DEBUG
  cout << "[" << element.date << "]" << endl;
  cout << "[" << element.time << "]" << endl;
  cout << "[" << element.pid << "]" << endl;
  cout << "[" << element.tid << "]" << endl;
  cout << "[" << element.priority << "]" << endl;
  cout << "[" << element.tag << "]" << endl;
  cout << "[" << element.message << "]" << endl;
  cout << ret << endl;
#endif

  EXPECT_STREQ("01-15", element.date.c_str());
  EXPECT_STREQ("21:30:21.080", element.time.c_str());
  EXPECT_EQ(1556, element.pid);
  EXPECT_EQ(1572, element.tid);
  EXPECT_STREQ("D", element.priority.c_str());
  EXPECT_STREQ("ProcessStatsService:", element.tag.c_str());
  EXPECT_STREQ("Prepared write state in 1ms", element.message.c_str());
  EXPECT_EQ(1, ret);

  delete ttparser;
}

/**
 * Test for bad format log message.
 */
TEST(ThreadtimeParser, parse_bad_message) {
  string testlog = "--------- beginning of main";
  element_t element;

  ThreadtimeParser *ttparser = new ThreadtimeParser();
  int ret = ttparser->parse(testlog, element);

  EXPECT_TRUE(element.date.empty());
  EXPECT_TRUE(element.time.empty());
  EXPECT_EQ(0, element.pid);
  EXPECT_EQ(0, element.tid);
  EXPECT_TRUE(element.priority.empty());
  EXPECT_TRUE(element.tag.empty());
  EXPECT_TRUE(element.message.empty());
  EXPECT_EQ(-1, ret);

  delete ttparser;
}
