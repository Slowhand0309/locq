#ifndef __LOCQ_H__
#define __LOCQ_H__
#include <iostream>
#include <cstdarg>
#include <sstream>
#include <string>
#include <fstream>
#include <termios.h>
#include <vector>

using namespace std;

namespace locq {

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



/**
 * SGR color enum.
 */
enum ANSICOLOR {
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};

/**
 * Option struct.
 */
typedef struct {
  // Priority color
  ANSICOLOR debugColor;
  ANSICOLOR infoColor;
  ANSICOLOR warnColor;
  ANSICOLOR errorColor;
  ANSICOLOR verboseColor;
} option_t;

/**
 * Log elements.
 */
typedef struct element {
  string date;
  string time;
  int uid;
  int pid;
  int tid;
  string package;
  string priority;
  string tag;
  string message;
  string orgmsg;

  element() {
    uid = 0;
    pid = 0;
    tid = 0;
  }
} element_t;

} // namespace locq

#endif // __LOCQ_H__
