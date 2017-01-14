#ifndef __VIEW_H__
#define __VIEW_H__
#include "locq.h"
#include "emitter.h"

namespace locq {

class View
{
public:
  View();
  View(ostream &_os);
  virtual ~View();

  virtual void draw() = 0;

protected:
  void newline();
  void clearScreen();

  int lfCount;
  ostream &os;
  Emitter emitter;
};

} // namespace locq

#endif // __VIEW_H__
