#include "view/view.h"

namespace locq {

View::View(ostream &_os)
  : os(_os)
{
  mode = NORMAL;
}

View::~View() {

}

void View::clearScreen() {
  system("clear");
}

} // namespace locq
