#ifndef __ANSI_EMITTER_H__
#define __ANSI_EMITTER_H__
#include "locq.h"

namespace locq {

/**
 * SGR color enum.
 */
enum ANSICOLOR {
  BLACK = 30,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};

/**
 * ANSI escape sequence manipulator class.
 */
class Emitter {

  /**
   * operator <<
   */
  friend ostream& operator <<(ostream& os, Emitter &m) {
    ostream& _os = m(os);
    m.empty();
    return _os;
  }

public:
  Emitter() {
  }

  virtual ~Emitter() {
    clear();
  }

  void empty() {
    str.clear();
  }

  Emitter& up(int n) {
    return emit(n, 'A');
  }

  Emitter& down(int n) {
    return emit(n, 'B');
  }

  Emitter& right(int n) {
    return emit(n, 'C');
  }

  Emitter& left(int n) {
    return emit(n, 'D');
  }

  Emitter& clearLine() {
    return emit(2, 'K');
  }

  Emitter& clear() {
    return emit(2, 'J');
  }

  Emitter& color(string text, ANSICOLOR c) {
    ostringstream stream;
    stream << "\e[" << c << 'm' << text << "\e[0m";
    str += stream.str();
    return *this;
  }

  Emitter& emit(int n, char code) {
    ostringstream stream;
    stream << "\e[" << n << code;
    str += stream.str();
    return *this;
  }
  string str;
private:

  ostream& operator()(ostream& os) {
    os << str;
    return os;
  }
};

} // namespace locq

#endif // __ANSI_EMITTER_H__
