
#ifndef ASTBuilder_h
#define ASTBuilder_h

#include <string>
#include "Lexer.h"

using namespace std;

namespace AJSC {
namespace Parser {

class ASTBuilder {

public:
  string m_currentIdentifier;
  Lexer m_lexer;

  ASTBuilder();

  void parse(string script);
};

}
} // End of namespace AJSC::Parser

#endif