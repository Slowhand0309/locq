#include "parser/threadtime_parser.h"

namespace locq {

// Min split num
#define SPLIT_SPACE_NUM (7)


ThreadtimeParser::ThreadtimeParser() {

}

ThreadtimeParser::~ThreadtimeParser() {

}

/**
 * parse message (-v threadtime)
 * e.g.
 *   01-15 21:01:12.211  1556  1962 I TAG: message
 *
 * @method ThreadtimeParser::parse
 * @param  message                 [description]
 * @param  element                 [description]
 * @return                         [description]
 */
int ThreadtimeParser::parse(string message, element_t &element) {
  // parse
  vector<string> v;
  string elem;

  string::iterator it;
  for (it = message.begin(); it != message.end(); ++it) {
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

  if (v.size() > SPLIT_SPACE_NUM - 1) {
    element.date = v[0];
    element.time = v[1];
    element.pid = stoi(v[2]);
    element.tid = stoi(v[3]);
    element.priority = v[4];
    element.tag = v[5];
    if (v.size() == SPLIT_SPACE_NUM) {
      element.message = v[6];
    } else {
      // Concat message.
      string text;
      for (int i = 6; i < v.size(); i++) {
        text += v[i];
        if (i != v.size() - 1) {
          text += " ";
        }
      }
      element.message = text;
    }

  } else {
    return -1;
  }

  return 1;
}

} // namespace locq
