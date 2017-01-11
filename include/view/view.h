#ifndef __VIEW_H__
#define __VIEW_H__
#include "session.h"

namespace locq {

class View
{
public:
  View();
  View(Session *s);
  virtual ~View();

  virtual void draw() = 0;

protected:
  Session *session;
  Emitter emitter;
};

} // namespace locq

#endif // __VIEW_H__
