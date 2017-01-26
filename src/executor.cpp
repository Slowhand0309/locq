#include "executor.h"
#include "parser/brief_parser.h"
#include "parser/process_parser.h"
#include "parser/threadtime_parser.h"
#include <thread>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <regex>

namespace locq {


Executor::Executor(option_t &options)
  : loopFlag(true)
  , session(NULL)
  , qv(NULL)
  , parser(NULL) {

  inputText = "";
  session = new Session();

  qv = new QueryView(options);
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
  thread th(&Executor::run, this);

  // main loop.
  while (loopFlag) {
    handleInput();

    // draw.
    qv->draw();

    // sleep
    usleep(50000);
  }

  // restart adb server
  system("adb kill-server && adb start-server");

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
    if (parser != NULL && parser->parse(line, element) > 0) {
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

  regex re_brief(FMT_REGEX_BRIEF);
  if (regex_search(message, re_brief)) {
    // logcat -v brief
    return new BriefParser();
  }
  regex re_process(FMT_REGEX_PROCESS);
  if (regex_search(message, re_process)) {
    // logcat -v process
    return new ProcessParser();
  }
  regex re_tag(FMT_REGEX_TAG);
  if (regex_search(message, re_tag)) {
    // logcat -v tag
    // TODO return parser
  }
  regex re_time(FMT_REGEX_TIME);
  if (regex_search(message, re_time)) {
    // logcat -v time
    // TODO return parser
  }

  regex re_threadtime(FMT_REGEX_THREADTIME);
  if (regex_search(message, re_threadtime)) {
    // logcat -v threadtime
    return new ThreadtimeParser();
  }
  return NULL;
}

} // namespace locq
