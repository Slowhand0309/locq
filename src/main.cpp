/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "view/query_view.h"

using namespace locq;

int main(int argc, char *argv[]) {
#if 0
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
#endif

  QueryView *qv = new QueryView();
  qv->draw();
  delete qv;

  return 1;
}
