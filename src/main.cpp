/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "ansi.h"
#include "session.h"
#include <fstream>

using namespace locq;

int main(int argc, char *argv[]) {

  Session *session = new Session();

  for (;;) {
    char ch = session->getchar();
    if (ch == 'q') {
      break;
    } else if (ch == 0) {
      continue;
    } else {
      cout << "input --> " << ch << endl;
      char hh = cin.get();
      cout << "cin --> " << hh << endl;
    }
  }

  delete session;
  return 1;
}
