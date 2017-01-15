#include "parser/threadtime_parser.h"

namespace locq {

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

  if (v.size() > 6) {
    element.date = v[0];
    element.time = v[1];
    element.pid = stoi(v[2]);
    element.tid = stoi(v[3]);
    element.priority = v[4];
    element.tag = v[5];
    element.message = v[6];
  }
}

} // namespace locq
