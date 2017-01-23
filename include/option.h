#ifndef __OPTION_H__
#define __OPTION_H__
#include "locq.h"

namespace locq {

class Option
{
public:

  /**
   * Parse arguments.
   *
   * @method parse
   * @param  options option_t struct
   * @param  argc
   * @param  argv
   */
  static void parse(option_t &options, int argc, char *argv[]);

  /**
   * Initialize option_t struct.
   *
   * @method initialize
   * @param  options    option_t struct
   */
  static void initialize(option_t &options);

private:
  Option();
  ~Option();
};

} // namespace locq

#endif // __OPTION_H__
