/*
 * Copyright 2017 Slowhand0309
 * All rights reserved.
 */
#include "view/query_view.h"
#include "session.h"
#include <iostream>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "emitter.h"

using namespace locq;

vector<string> list;
bool flag = true;
Emitter emitter;

void worker() {
  string line;
  while(flag && getline(cin, line)) {
    // parse
    vector<string> v;
    string elem;
    for (string::iterator it = line.begin(); it != line.end(); ++it) {
      char c = *it;
      if (c == ' ' && !elem.empty()) {
        v.push_back(elem);
        elem.clear();
      } else {
        elem += c;
      }
    }
    if (!elem.empty()) {
      v.push_back(elem);
    }
    if (v.size() > 5) {
      list.push_back(v[5]);
    }
  }
  flag = false;
}

void handleInput(Session *session, string &text) {
  char ch = session->getchar();
  if (ch == 'q') {
    flag = false;
  } else {
    text += ch;
  }
}

/**
 * Entry point.
 *
 * @method main
 * @param  argc
 * @param  argv
 * @return      [result code]
 */
int main(int argc, char *argv[]) {

  thread th(worker);

  int index = 0;
  string inputText = "";

  Session *session = new Session();

  QueryView *qv = new QueryView();
  qv->setup(&inputText, &list, &index);

  // main loop.
  while (flag) {
    //clearScreen();
    handleInput(session, inputText);
    qv->draw();
  }

  delete qv;
  delete session;
  // Session *session = new Session();
  //
  // for (;;) {
  //   char ch = session->getchar();
  //   if (ch == 'q') {
  //     break;
  //   } else if (ch == 0) {
  //     continue;
  //   } else {
  //     cout << "input --> " << ch << endl;
  //     cout << "vector size " << list.size() << endl;
  //   }
  // }
  //
  // delete session;

  th.join();

  return 1;
}
