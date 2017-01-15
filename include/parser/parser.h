#ifndef __PARSER_H__
#define __PARSER_H__
#include "locq.h"

namespace locq {

class Parser
{
public:
  Parser();
  virtual ~Parser();

  virtual int parse(string message, element_t &element) = 0;
};

} // namespace locq

#endif // __PARSER_H__
