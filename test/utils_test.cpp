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
