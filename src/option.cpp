#include "option.h"
#include <getopt.h>

namespace locq {

Option::Option() {
}

Option::~Option() {
}

void Option::parse(option_t &options, int argc, char *argv[]) {

  initialize(options);

  int r = 0;
  while ((r = getopt(argc, argv, "v")) != -1) {
    switch (r) {
      case 'v':
        // Show version.
        cout << "locq " << VERSION << " (c) Slowhand0309\n" << endl;
        exit(EXIT_SUCCESS);
    }
  }
}

void Option::initialize(option_t &options) {

  options.debugColor = MAGENTA;
  options.infoColor = BLUE;
  options.warnColor = YELLOW;
  options.errorColor = RED;
  options.verboseColor = WHITE;

}

} // namespace locq
