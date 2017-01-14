#ifndef __EXECUTOR_H__
#define __EXECUTOR_H__
#include "locq.h"
#include "session.h"
#include "view/query_view.h"

namespace locq {

class Executor
{
public:
  Executor();
  virtual ~Executor();

  void exec();

private:
  void run(bool &flag);
  void handleInput();

  Session *session;
  QueryView *qv;

  vector<string> logList;
  string inputText;
  bool loopFlag;
};

} // namespace locq

#endif // __EXECUTOR_H__
