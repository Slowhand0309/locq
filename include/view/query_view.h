#ifndef __QUERY_VIEW_H__
#define __QUERY_VIEW_H__
#include "view/view.h"

namespace locq {

class QueryView : public View
{
public:
  QueryView();
  QueryView(Session *s);
  virtual ~QueryView();

  virtual void draw();

};

} // namespace locq

#endif // __QUERY_VIEW_H__
