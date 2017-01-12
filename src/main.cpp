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

  int index = 0;
  string text = "android";
  vector<string> list;
  list.push_back("12345fdhfd_android_fdsfdsf");
  list.push_back("67889dfsfdaandroidfdsdf");
  list.push_back("abcder54y5ey5yfhd");

  QueryView *qv = new QueryView();
  qv->setup(&text, &list, &index);
  qv->draw();
  delete qv;

  return 1;
}
