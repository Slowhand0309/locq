#include "session.h"
#include <fcntl.h>

namespace locq {

Session::Session()
: Session("/dev/tty") {

}

Session::Session(const char *tty)
  : fin(tty), fout(tty)
{
  int fd = open(tty, O_RDONLY);
  if (tcgetattr(fd, &org)) {
    perror("tcgetattr faild");
  }
}

Session::~Session() {

}

void Session::write(const char *text) {
  fout << text;
}

} // namespace locq
