#ifndef __SESSION_H_
#define __SESSION_H_
#include "locq.h"

namespace locq {

class Session
{
public:
  Session();
  Session(const char *tty);
  virtual ~Session();

  void write(const char *text);
  void write(string str);
  char getchar();

private:
  int available();

  int fd;
  fd_set rfds;

  ifstream fin;
  ofstream fout;
  struct termios org;
};

} // namespace locq

#endif // __SESSION_H_
