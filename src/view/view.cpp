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

ANSICOLOR View::toColor(string &priority) {
  ANSICOLOR color = WHITE; // default
  if (priority == "D") {
    color = option->debugColor();
  } else if (priority == "I") {
    color = option->infoColor();
  } else if (priority == "W") {
    color = option->warnColor();
  } else if (priority == "E") {
    color = option->errorColor();
  } else if (priority == "V") {
    color = option->verboseColor();
  }
  return color;
}

} // namespace locq
