
#include "ASTBuilder.h"
#include "Lexer.h"
#include <string>
#include <iostream>

using namespace std;

namespace AJSC {
namespace Parser {

ASTBuilder::ASTBuilder(): m_currentIdentifier("") {}

void Parser::ASTBuilder::parse(string source) {
  m_lexer = Lexer(source);
  while(true) {

  }
}

}
}