/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "ansi.h"

using namespace locq;

int main(int argc, char *argv[]) {

  string str("testabcdefg\n");

  Ansi ansi(cout);
  ansi.printColor(str, RED);
  ansi.printColor(str, CYAN);
  ansi.right(0);
  ansi.up(0);
  ansi.printColor("string()", GREEN);

  return 1;
}
