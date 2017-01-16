#ifndef __OPTION_H__
#define __OPTION_H__
#include "locq.h"

namespace locq {

class Option
{
public:
  static Option *getInstance();
  static void release();

  ANSICOLOR debugColor();
  ANSICOLOR infoColor();
  ANSICOLOR warnColor();
  ANSICOLOR errorColor();
  ANSICOLOR verboseColor();

private:
  static Option *instance;

  Option();
  ~Option();

  void init();

  option_t options;
};

} // namespace locq

#endif // __OPTION_H__
