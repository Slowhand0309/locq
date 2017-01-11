#include "view/query_view.h"

namespace locq {

QueryView::QueryView()
  : View()
{
}

QueryView::QueryView(Session *s)
  : View(s)
{
}

QueryView::~QueryView() {

}

void QueryView::draw() {
  cout << emitter.color("QUERY > ", WHITE);

}

} // namespace locq
