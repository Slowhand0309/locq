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

#endif // __LOCQ_H__
