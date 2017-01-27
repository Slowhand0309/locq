#include "utils.h"
#include <functional>
#include <algorithm>

namespace locq {

string Utils::replace(string str, string from, string to) {
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


void Utils::split(string &str, string &delim, vector<string> &list, bool includeDelim) {

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
    if (includeDelim) {
      list.push_back(delim);
    }
    pos = p + delim.size();
  }
}

void Utils::ltrim(string &str) {
  string::iterator p = find_if(str.begin(), str.end(), not1(ptr_fun<int, int>(isspace)));
  str.erase(str.begin(), p);
}

void Utils::rtrim(string &str) {
  string::iterator p = find_if(str.rbegin(), str.rend(), not1(ptr_fun<int, int>(isspace))).base();
  str.erase(p, str.end());
}

void Utils::trim(string &str) {
  rtrim(str);
  ltrim(str);
}

} // namespace locq
