#include "view/query_view.h"
#include "utils.h"

namespace locq {

QueryView::QueryView()
  : View()
{
  lfCount = 0;
}

QueryView::QueryView(ostream &_os)
  : View(_os)
{
  lfCount = 0;
}

QueryView::~QueryView() {
  // remove reference
  matcher = NULL;
  dataList = NULL;
}

void QueryView::setup(string *str, vector<string> *list) {
  matcher = str;
  dataList = list;
}

void QueryView::draw() {

  clearScreen();
  // draw query text.
  os << emitter.color("QUERY : ", WHITE);
  os << *matcher;
  newline();

  os << emitter.color(">", CYAN);
  newline();

  // draw target list.
  int i = 0;
  vector<string>::iterator it;
  for (it = dataList->begin(); it != dataList->end(); ++it, ++i) {
    // if (i == *index) {
    //   os << toSelectedMatchText(*it, *matcher);
    // } else {
    if (matcher->empty()) {
      os << *it;
    } else {
      os << toMatchText(*it, *matcher);
    }
    // }
    newline();
    if (i > 5) {
      break;
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
