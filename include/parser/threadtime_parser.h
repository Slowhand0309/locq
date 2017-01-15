#ifndef __THREADTIME_PARSER_H__
#define __THREADTIME_PARSER_H__
#include "parser/parser.h"

namespace locq {

class ThreadtimeParser : public Parser
{
public:
  ThreadtimeParser();
  virtual ~ThreadtimeParser();

  virtual int parse(string message, element_t &element);
};

} // namespace locq

#endif // __THREADTIME_PARSER_H__
