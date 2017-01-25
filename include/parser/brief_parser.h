#ifndef __BRIEF_PARSER_H__
#define __BRIEF_PARSER_H__
#include "parser/parser.h"

namespace locq {

class BriefParser : public Parser
{
public:
  BriefParser();
  virtual ~BriefParser();

  virtual int parse(string message, element_t &element);
};

} // namespace locq

#endif // __BRIEF_PARSER_H__
