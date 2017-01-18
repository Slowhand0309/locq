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
  // Delete option
  Option::release();
}

void Executor::exec() {
  thread th(&Executor::run, this);

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

void Executor::run() {
  string line;
  while(getline(cin, line)) {
    // parse
    if (parser == NULL) {
      parser = getParser(line);
    }
    element_t element;
    if (parser->parse(line, element) > 0) {
      logList.push_back(element);
    }
  }
}

void Executor::handleInput() {
  char ch = session->getchar();
  if (ch == 0) {
    // Do nothing.
  } else if (ch == 0x1b) {
    // 'ESC' key
    loopFlag = false;
  } else if (ch == 0x7F) {
    // 'Back space' key
    if (!inputText.empty()) {
      inputText = inputText.substr(0, inputText.size() - 1);
    }
  } else {
    inputText += ch;
  }
}

Parser *Executor::getParser(string message) {
  // TODO
  return new ThreadtimeParser();
}

} // namespace locq
