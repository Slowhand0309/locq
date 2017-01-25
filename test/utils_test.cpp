#include <gtest/gtest.h>
#include "utils.h"

using namespace locq;

/**
 * Test for replace string.
 */
TEST(Utils, replace) {

  // replace
  string org = "Locq xxx test.";
  string from = "xxx";
  string to = "utils::replace";

  string result = Utils::replace(org, from, to);
  EXPECT_STREQ("Locq utils::replace test.", result.c_str());

  // not match
  string from2 = "hoge";
  string result2 = Utils::replace(org, from2, to);
  EXPECT_STREQ(org.c_str(), result2.c_str());
}

/**
 * Test for split string.
 */
TEST(Utils, split) {
  // split
  string org = "csv,data1,data2";
  string delim = ",";
  vector<string> result;
  Utils::split(org, delim, result);
  EXPECT_EQ(3, result.size());
  EXPECT_STREQ("csv", result[0].c_str());
  EXPECT_STREQ("data1", result[1].c_str());
  EXPECT_STREQ("data2", result[2].c_str());

  // include delimiter
  vector<string> result2;
  Utils::split(org, delim, result2, true);
  EXPECT_EQ(5, result2.size());
  EXPECT_STREQ("csv", result2[0].c_str());
  EXPECT_STREQ(delim.c_str(), result2[1].c_str());
  EXPECT_STREQ("data1", result2[2].c_str());
  EXPECT_STREQ(delim.c_str(), result2[3].c_str());
  EXPECT_STREQ("data2", result2[4].c_str());
}

/**
 * Test for ltrim string.
 */
TEST(Utils, ltrim) {
  // ltrim
  string str1 = " trim left side. ";
  Utils::ltrim(str1);
  EXPECT_STREQ("trim left side. ", str1.c_str());

  string str2 = "not space left. ";
  Utils::ltrim(str2);
  EXPECT_STREQ("not space left. ", str2.c_str());
}

/**
 * Test for rtrim string.
 */
TEST(Utils, rtrim) {
  // ltrim
  string str1 = " trim right side. ";
  Utils::rtrim(str1);
  EXPECT_STREQ(" trim right side.", str1.c_str());

  string str2 = " not space right.";
  Utils::rtrim(str2);
  EXPECT_STREQ(" not space right.", str2.c_str());
}

/**
 * Test for trim string.
 */
TEST(Utils, trim) {
  // ltrim
  string str1 = "  trim both side.  ";
  Utils::trim(str1);
  EXPECT_STREQ("trim both side.", str1.c_str());

  string str2 = "not space both side.";
  Utils::trim(str2);
  EXPECT_STREQ("not space both side.", str2.c_str());
}
