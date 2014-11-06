
#ifndef ASTBuilder_h
#define ASTBuilder_h

#include <string>
#include "Lexer.h"

using namespace std;

namespace AJSC {
namespace Parser {

class ASTBuilder {
  Lexer lexer;
public:
  int m_currentIdentifier;

  void parse(string script);
};

}
} // End of namespace AJSC::Parser

#endif