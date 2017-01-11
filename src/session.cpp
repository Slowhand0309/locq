#include "session.h"
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

namespace locq {

Session::Session()
: Session("/dev/tty") {

}

Session::Session(const char *tty)
  : fin(tty), fout(tty)
{
  fd = open(tty, O_RDONLY);
  if (tcgetattr(fd, &org)) {
    perror("tcgetattr faild");
  }

  struct termios new_termios = org;
  new_termios.c_iflag &= ~(ICRNL);
  new_termios.c_lflag &= ~(ICANON | ECHO | ISIG);
  if (tcsetattr(fd, TCSANOW, &new_termios)) {
    perror("tcsetattr failed");
  }
}

Session::~Session() {

}

void Session::write(const char *text) {
  fout << text;
}

void Session::write(string str) {
  fout << str;
}

char Session::getchar() {
  char ch = 0;
  if (available()) {
    read(fd, &ch, 1);
  }
  return ch;
}

int Session::available() {
  struct timeval tv = {0, 0};
  FD_SET(fd, &rfds);
  if (select(fd + 1, &rfds, NULL, NULL, &tv) < 0) {
    perror("select failed");
  }
  return FD_ISSET(fd, &rfds);
}

} // namespace locq
