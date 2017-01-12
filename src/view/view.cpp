#include "view/view.h"

namespace locq {

View::View()
  : View(cout)
{
}

View::View(ostream &_os)
  : os(_os)
{
}

View::~View() {

}

} // namespace locq
