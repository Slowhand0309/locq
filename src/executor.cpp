#include "executor.h"
#include "parser/threadtime_parser.h"
#include <thread>
#include <unistd.h>

namespace locq {

Executor::Executor()
  : loopFlag(true)
  , session(NULL)
  , qv(NULL)
  , parser(NULL) {

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
  if (parser != NULL) {
    delete parser;
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
    usleep(50000);
  }

  th.detach();
}

void Executor::run(bool &flag) {
  string line;
  while(flag && getline(cin, line)) {
    // parse
    if (parser == NULL) {
      parser = getParser(line);
    }
    element_t element;
    if (parser->parse(line, element) > 0) {
      logList.push_back(element);
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

Parser *Executor::getParser(string message) {
  // TODO
  return new ThreadtimeParser();
}

} // namespace locq
