#ifndef __QUERY_VIEW_H__
#define __QUERY_VIEW_H__
#include "view/view.h"

namespace locq {

class QueryView : public View
{
public:
  QueryView();
  QueryView(ostream &_os);
  virtual ~QueryView();

  virtual void draw();

  void setup(string *str, vector<element_t> *list);

private:
  void drawRecentLog();
  void drawPriorityColor(element_t &elem);
  void drawMatchPriorityColor(element_t &elem, string &matcher);

  string toMatchText(string org, string matcher);
  string toSelectedMatchText(string org, string matcher);

  string *matcher;
  vector<element_t> *dataList;
};

} // namespace locq

#endif // __QUERY_VIEW_H__
