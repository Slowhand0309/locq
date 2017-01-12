#include "view/query_view.h"
#include "utils.h"

namespace locq {

QueryView::QueryView()
  : View()
{
}

QueryView::QueryView(ostream &_os)
  : View(_os)
{
}

QueryView::~QueryView() {
  // remove reference
  matcher = NULL;
  dataList = NULL;
  index = NULL;
}

void QueryView::setup(string *str, vector<string> *list, int *idx) {
  matcher = str;
  dataList = list;
  index = idx;
}

void QueryView::draw() {
  // draw query text.
  os << emitter.color("QUERY : ", WHITE);
  os << *matcher << endl;

  os << emitter.color(">", CYAN) << endl;

  // draw target list.
  int i = 0;
  vector<string>::iterator it;
  for (it = dataList->begin(); it != dataList->end(); ++it, ++i) {
    if (i == *index) {
      os << toSelectedMatchText(*it, *matcher) << endl;
    } else {
      os << toMatchText(*it, *matcher) << endl;
    }
  }
}

string QueryView::toMatchText(string org, string matcher) {

  string color = emitter.color(matcher, CYAN).getRow();
  emitter.empty();

  return Utils::replace(org, matcher, color);
}

string QueryView::toSelectedMatchText(string org, string matcher) {
  // split text.
  vector<string> v;
  Utils::split(org, matcher, v);

  ostringstream stream;
  vector<string>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    string text = *it;
    if (text == matcher) {
      text = emitter.color(*it, CYAN).getRow();
      emitter.empty();
    }
    stream << emitter.background(text, MAGENTA);
  }
  return stream.str();
}

} // namespace locq
