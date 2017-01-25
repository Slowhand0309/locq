#include "parser/brief_parser.h"
#include "utils.h"
#include <regex>

namespace locq {


BriefParser::BriefParser() {

}

BriefParser::~BriefParser() {

}

/**
 * Parse message (-v brief)
 * e.g.
 *  I/ActivityManager( 1556): message
 *
 * @method BriefParser::parse
 * @param  message            [description]
 * @param  element            [description]
 * @return                    [description]
 */
int BriefParser::parse(string message, element_t &element) {
  // parse
  regex re(FMT_REGEX_BRIEF);
  smatch match;

  if (regex_search(message, match, re)) {
    if (match.size() > 4) {
      element.priority = match[1];
      element.tag = match[2];
      string str = match[3];
      Utils::ltrim(str);
      element.pid = stoi(str);
      element.message = match[4];
      element.orgmsg = message;
    }
    return 1;
  }
  return -1;
}

} // namespace locq
