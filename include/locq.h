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

  element() {
    uid = 0;
    pid = 0;
    tid = 0;
  }
} element_t;

#endif // __LOCQ_H__
