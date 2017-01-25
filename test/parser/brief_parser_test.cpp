#include <gtest/gtest.h>
#include "parser/brief_parser.h"

using namespace locq;

//#define DEBUG

/**
 * Test for normal log message.
 */
TEST(BriefParser, parse_normal) {
  string testlog = "I/ActivityManager( 1556): Killing 2166:com.google.android.apps.maps/u0a38 (adj 13): empty for 1805s";
  element_t element;

  BriefParser *parser = new BriefParser();
  int ret = parser->parse(testlog, element);

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

  EXPECT_STREQ("", element.date.c_str());
  EXPECT_STREQ("", element.time.c_str());
  EXPECT_EQ(1556, element.pid);
  EXPECT_EQ(0, element.tid);
  EXPECT_STREQ("I", element.priority.c_str());
  EXPECT_STREQ("ActivityManager", element.tag.c_str());
  EXPECT_STREQ("Killing 2166:com.google.android.apps.maps/u0a38 (adj 13): empty for 1805s", element.message.c_str());
  EXPECT_STREQ(testlog.c_str(), element.orgmsg.c_str());
  EXPECT_EQ(1, ret);

  delete parser;
}

/**
 * Test for bad format log message.
 */
TEST(BriefParser, parse_bad_message) {
  string testlog = "--------- beginning of main";
  element_t element;

  BriefParser *parser = new BriefParser();
  int ret = parser->parse(testlog, element);

  EXPECT_TRUE(element.date.empty());
  EXPECT_TRUE(element.time.empty());
  EXPECT_EQ(0, element.pid);
  EXPECT_EQ(0, element.tid);
  EXPECT_TRUE(element.priority.empty());
  EXPECT_TRUE(element.tag.empty());
  EXPECT_TRUE(element.message.empty());
  EXPECT_TRUE(element.orgmsg.empty());
  EXPECT_EQ(-1, ret);

  delete parser;
}
