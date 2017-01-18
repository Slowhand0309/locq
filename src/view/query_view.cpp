#include "view/query_view.h"
#include "utils.h"

namespace locq {

QueryView::QueryView()
  : QueryView(cout)
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
}

void QueryView::setup(string *str, vector<element_t> *list) {
  matcher = str;
  dataList = list;
}

void QueryView::draw() {

  clearScreen();
  // draw query text.
  os << emitter.color("QUERY : ", WHITE);
  os << *matcher << endl;

  os << emitter.color(">", CYAN) << endl;

  // draw target list.
  drawRecentLog();

#if 0
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
#endif
}

void QueryView::drawRecentLog() {

  int idx = 0;
  vector<element_t>::reverse_iterator rit;
  for (rit = dataList->rbegin(); rit != dataList->rend(); ++rit, ++idx) {
    if (matcher->empty()) {
      //os << rit->orgmsg << endl;
      drawPriorityColor(*rit);
    } else {
      if (rit->orgmsg.find(*matcher) != string::npos) {
        drawMatchPriorityColor(*rit, *matcher);
      }
    }
    if (idx > 5) {
      break;
    }
  }
}

void QueryView::drawPriorityColor(element_t &elem) {
  ANSICOLOR color = toColor(elem.priority);
  os << emitter.color(elem.orgmsg, color) << endl;
}

void QueryView::drawMatchPriorityColor(element_t &elem, string &matcher) {
  ANSICOLOR color = toColor(elem.priority);

  // split text.
  vector<string> v;
  Utils::split(elem.orgmsg, matcher, v, true);

  ostringstream stream;
  vector<string>::iterator it;
  for (it = v.begin(); it != v.end(); ++it) {
    string text = *it;
    if (text == matcher) {
      text = emitter.color(*it, CYAN).getRow();
      emitter.empty();
    }
    stream << emitter.color(text, color);
  }
  os << stream.str() << endl;
}

string QueryView::toMatchText(string org, string matcher) {

  string color = emitter.color(matcher, CYAN).getRow();
  emitter.empty();

  return Utils::replace(org, matcher, color);
}

string QueryView::toSelectedMatchText(string org, string matcher) {
  // split text.
  vector<string> v;
  Utils::split(org, matcher, v, true);

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
