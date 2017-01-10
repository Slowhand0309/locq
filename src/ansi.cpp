#include "ansi.h"

namespace locq {


Ansi::Ansi(ostream& _fd)
 : fd(_fd) {
}

Ansi::~Ansi() {
}

void Ansi::up(int n) {
  fd << escfmt(n, 'A');
}

void Ansi::down(int n) {
  fd << escfmt(n, 'B');
}

void Ansi::right(int n) {
  fd << escfmt(n, 'C');
}

void Ansi::left(int n) {
  fd << escfmt(n, 'D');
}

void Ansi::printColor(string str, ANSICOLOR ansiColor) {
  fd << SGRFORMAT(ansiColor) << str << SGRRESET;
}

void Ansi::clearLine() {
  fd << escfmt(2, 'K');
}

void Ansi::clear() {
  fd << escfmt(2, 'J');
}


} // namespace locq
