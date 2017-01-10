#ifndef __ANSI_H__
#define __ANSI_H__
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
 * Escape format manipulator.
 */
class escfmt {
  friend ostream& operator <<(ostream& os, escfmt m) {
    return m(os);
  }

public:
  escfmt(int n, char code) {
    ostringstream stream;
    stream << "\e[" << n << code;
    str = stream.str();
  }

private:
  string str;
  ostream& operator()(ostream& os) {
    os << str;
    return os;
  }
};


#define ESCFORMAT     "\e[%i%c"
#define ESCFORMAT_ARG "\e[%i;%i%c"

#define SGRFORMAT(n)     escfmt(n, 'm')
#define SGRRESET         escfmt(0, 'm')



class Ansi
{
public:
  Ansi(ostream& _fd);
  virtual ~Ansi();

  // Cursor operation.
  void up(int n);
  void down(int n);
  void right(int n);
  void left(int n);

  // Color
  void printColor(string str, ANSICOLOR ansiColor);

  // clear display.
  void clearLine();
  void clear();

private:

  ostream& fd;
};

} // namespace locq

#endif // __ANSI_H__
