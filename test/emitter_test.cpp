#include <gtest/gtest.h>
#include "emitter.h"

using namespace locq;

/**
 * Test for moving escape sequence.
 */
TEST(Emitter, moving) {
  Emitter emitter;
  EXPECT_STREQ("\e[2A", emitter.up(2).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[1B", emitter.down(1).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[3C", emitter.right(3).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[1D", emitter.left(1).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[2E", emitter.moveLineDown(2).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[3F", emitter.moveLineUp(3).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[1G", emitter.moveLeft(1).getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[0K", emitter.clearLine().getRow().c_str());
  emitter.empty();
  EXPECT_STREQ("\e[2J", emitter.clear().getRow().c_str());
  emitter.empty();
}

/**
 * Test for color escape sequence.
 */
TEST(Emitter, color) {
 Emitter emitter;
 EXPECT_STREQ("\e[30mblack\e[0m", emitter.color("black", BLACK).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[31mred\e[0m", emitter.color("red", RED).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[32mgreen\e[0m", emitter.color("green", GREEN).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[33myellow\e[0m", emitter.color("yellow", YELLOW).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[34mblue\e[0m", emitter.color("blue", BLUE).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[35mmagenta\e[0m", emitter.color("magenta", MAGENTA).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[36mcyan\e[0m", emitter.color("cyan", CYAN).getRow().c_str());
 emitter.empty();
 EXPECT_STREQ("\e[37mwhite\e[0m", emitter.color("white", WHITE).getRow().c_str());
 emitter.empty();
}
