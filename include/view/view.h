#ifndef __VIEW_H__
#define __VIEW_H__
#include "locq.h"
#include "emitter.h"
#include "option.h"

namespace locq {

enum VIEWMODE {
  NORMAL,
  QUERY
};

class View
{
public:
  View(ostream &_os);
  virtual ~View();

  virtual void draw() = 0;

protected:
  virtual void clearScreen();
  virtual ANSICOLOR toColor(string &priority);

  ostream &os;
  Emitter emitter;
  VIEWMODE mode;
  Option *option;
};

} // namespace locq

#endif // __VIEW_H__
