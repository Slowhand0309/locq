#include "view/view.h"

namespace locq {

View::View(ostream &_os, option_t &_options)
  : os(_os)
  , options(_options)
{
  mode = NORMAL;
}

View::~View() {

}

void View::clearScreen() {
  system("clear");
}

ANSICOLOR View::toColor(string &priority) {
  ANSICOLOR color = WHITE; // default
  if (priority == "D") {
    color = options.debugColor;
  } else if (priority == "I") {
    color = options.infoColor;
  } else if (priority == "W") {
    color = options.warnColor;
  } else if (priority == "E") {
    color = options.errorColor;
  } else if (priority == "V") {
    color = options.verboseColor;
  }
  return color;
}

} // namespace locq
