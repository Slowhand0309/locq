#include "parser/process_parser.h"
#include "utils.h"
#include <regex>

namespace locq {

ProcessParser::ProcessParser() {

}

ProcessParser::~ProcessParser() {

}

/**
 * Parse message (logcat -v process)
 * e.g.
 *  I/AccountManagerService: getTypesVisibleToCaller: isPermitted? true
 *
 * @method ProcessParser::parse
 * @param  message              [description]
 * @param  element              [description]
 * @return                      [description]
 */
int ProcessParser::parse(string message, element_t &element) {
  // parse
  regex re(FMT_REGEX_PROCESS);
  smatch match;

  if (regex_search(message, match, re)) {
    if (match.size() > 4) {
      element.priority = match[1];
      string str = match[2];
      Utils::ltrim(str);
      element.pid = stoi(str);
      element.message = match[3];
      element.tag = match[4];
      element.orgmsg = message;
    }
    return 1;
  }
  return -1;
}


} // namespace locq
