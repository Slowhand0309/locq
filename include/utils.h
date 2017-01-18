#ifndef __UTILS_H__
#define __UTILS_H__
#include "locq.h"

namespace locq {

class Utils
{
public:
  /**
   * Replace [from] -> [to] in str.
   *
   * @method replace
   * @param  str     [org text]
   * @param  from    [replace from]
   * @param  to      [replace to]
   * @return         [replaced text]
   */
  static string replace(string str, string from, string to);

  static void split(string &str, string &delim, vector<string> &list, bool includeDelim = false);

private:
  // Not construct.
  Utils() {};
  ~Utils() {};
};

} // namespace locq

#endif // __UTILS_H__
