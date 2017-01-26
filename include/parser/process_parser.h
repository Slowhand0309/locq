#ifndef __PROCESS_PARSER_H__
#define __PROCESS_PARSER_H__
#include "parser/parser.h"

namespace locq {

class ProcessParser : public Parser
{
public:
  ProcessParser();
  virtual ~ProcessParser();

  virtual int parse(string message, element_t &element);
};

} // namespace locq

#endif // __PROCESS_PARSER_H__
