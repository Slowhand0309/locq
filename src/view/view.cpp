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

void View::newline() {
  lfCount++;
  os << endl;
}

void View::clearScreen() {
  for (int i = 0; i < lfCount; i++) {
    os << emitter.moveLeft(1);
    os << emitter.clearLine();
    os << emitter.moveLineUp(1);
  }
  lfCount = 0;
}

} // namespace locq
