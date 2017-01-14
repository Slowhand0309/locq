#include "executor.h"
#include <thread>
#include <unistd.h>

namespace locq {

Executor::Executor()
  : loopFlag(true)
  , session(NULL)
  , qv(NULL) {

  inputText = "";
  session = new Session();

  qv = new QueryView();
  qv->setup(&inputText, &logList);
}

Executor::~Executor() {
  if (qv != NULL) {
    delete qv;
  }
  if (session != NULL) {
    delete session;
  }
}

void Executor::exec() {
  thread th(&Executor::run, this, ref(loopFlag));

  // main loop.
  while (loopFlag) {
    handleInput();

    // draw.
    qv->draw();

    // sleep
    usleep(30000);
  }

  th.detach();
}

void Executor::run(bool &flag) {
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
      logList.push_back(v[5]);
    }
  }
  flag = false;
}

void Executor::handleInput() {
  char ch = session->getchar();
  if (ch == 0) {
    // Do nothing.
  } else if (ch == 0x1b) {
    // 'ESC' key
    loopFlag = false;
  } else {
    inputText += ch;
  }
}

} // namespace locq
