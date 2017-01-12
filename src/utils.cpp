#include "utils.h"

namespace locq {

string Utils::replace(string &str, string &from, string &to) {
  string::size_type pos(str.find(from));

  for (;;) {
    if (pos == string::npos) {
      break;
    }
    str.replace(pos, from.length(), to);
    pos = str.find(from, pos + to.length());
  }
  return str;
}


void Utils::split(string &str, string &delim, vector<string> &list) {

  list.clear();
  string::size_type pos = 0;

  for (;;) {
    if (pos == string::npos) {
      break;
    }
    string::size_type p = str.find(delim, pos);
    if (p == string::npos) {
      list.push_back(str.substr(pos));
      break;
    } else {
      list.push_back(str.substr(pos, p - pos));
    }
    list.push_back(delim);
    pos = p + delim.size();
  }
}

} // namespace locq
