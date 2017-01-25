#include <gtest/gtest.h>
#include <regex>

using namespace std;

// logcat -v brief
#define FMT_REGEX_BRIEF "^([VDIWEF])\\/([a-zA-Z\\s\\d-]+)\\(([\\s|\\d]\\d*)\\):\\s(.*)"
// logcat -v process
#define FMT_REGEX_PROCESS "^([VDIWEF])\\(([\\s|\\d]\\d*)\\)\\s(.*)\\(([a-zA-Z\\s\\d-]+)\\)"
// logcat -v tag
#define FMT_REGEX_TAG "^([VDIWEF])\\/([a-zA-Z\\s\\d-]+):\\s(.*)"
// logcat -v time
#define FMT_REGEX_TIME  "^(\\d{2}-\\d{2})\\s(\\d{2}:\\d{2}:\\d{2}.\\d{3})\\s([VDIWEF])\\/([a-zA-Z\\s\\d-]+)\\(([\\s|\\d]\\d*)\\):\\s(.*)"
// logcat -v threadtime
#define FMT_REGEX_THREADTIME  "^(\\d{2}-\\d{2})\\s+(\\d{2}:\\d{2}:\\d{2}.\\d{3})\\s+(\\d+)\\s+(\\d+)\\s+([VDIWEF])\\s+([a-zA-Z\\s\\d-]+):\\s(.*)"

TEST(RegexParser, brief) {

  string message = "I/AccountManagerService( 1556): getTypesVisibleToCaller: isPermitted? true";

  regex re(FMT_REGEX_BRIEF);
  EXPECT_TRUE(regex_search(message, re));
}

TEST(RegexParser, process) {
  string message = "I( 1556) getTypesVisibleToCaller: isPermitted? true  (AccountManagerService)";

  regex re(FMT_REGEX_PROCESS);
  EXPECT_TRUE(regex_search(message, re));
}

TEST(RegexParser, tag) {
  string message = "W/ContentTaskController: Invalid task was provided to stopTracking.";

  regex re(FMT_REGEX_TAG);
  EXPECT_TRUE(regex_search(message, re));
}

TEST(RegexParser, time) {
  string message = "01-24 13:03:48.296 I/GAv4-SVC( 2301): Google Analytics 10.0.84 is starting up.";

  regex re(FMT_REGEX_TIME);
  EXPECT_TRUE(regex_search(message, re));
}

TEST(RegexParser, threadtime) {

  string message = "01-24 13:01:22.570  1192  1192 W auditd  : type=2000 audit(0.0:1): initialized";

  regex re(FMT_REGEX_THREADTIME);
  EXPECT_TRUE(regex_search(message, re));
}
