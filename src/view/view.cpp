#include "view/view.h"

namespace locq {

View::View(ostream &_os)
  : os(_os)
{
  mode = NORMAL;
  option = Option::getInstance();
}

View::~View() {

}

void View::clearScreen() {
  system("clear");
}

} // namespace locq
