#include "view/view.h"

namespace locq {

View::View()
  : View(new Session())
{
}

View::View(Session *s)
  : session(s)
{
}

View::~View() {

}

} // namespace locq
