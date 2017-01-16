#include "option.h"

namespace locq {

Option *Option::instance = NULL;

Option *Option::getInstance() {
  if (Option::instance == NULL) {
    Option::instance = new Option();
  }
  return instance;
}

void Option::release() {
  if (Option::instance != NULL) {
    delete Option::instance;
    Option::instance = NULL;
  }
}

Option::Option() {
  init();
}

Option::~Option() {

}

void Option::init() {

  options.debugColor = MAGENTA;
  options.infoColor = BLUE;
  options.warnColor = YELLOW;
  options.errorColor = RED;
  options.verboseColor = WHITE;

}

ANSICOLOR Option::debugColor() {
  return options.debugColor;
}

ANSICOLOR Option::infoColor() {
  return options.infoColor;
}

ANSICOLOR Option::warnColor() {
  return options.warnColor;
}

ANSICOLOR Option::errorColor() {
  return options.errorColor;
}

ANSICOLOR Option::verboseColor() {
  return options.verboseColor;
}

} // namespace locq
