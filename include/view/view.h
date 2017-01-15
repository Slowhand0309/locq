#ifndef __VIEW_H__
#define __VIEW_H__
#include "locq.h"
#include "emitter.h"

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
  void clearScreen();

  ostream &os;
  Emitter emitter;
  VIEWMODE mode;
};

} // namespace locq

#endif // __VIEW_H__
