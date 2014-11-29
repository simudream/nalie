
#include "ASTBuilder.h"
#include "Lexer.h"
#include "Identifiers.h"
#include <string>
#include <iostream>

using namespace std;

namespace AJSC {
namespace Parser {

ASTBuilder::ASTBuilder(): m_currentIdentifier("") {}

void ASTBuilder::parse(string source) {
  m_lexer = Lexer(source);
  while(isalnum(m_lexer.getToken())) {
    m_currentIdentifier += m_lexer.m_currentToken;
  }

  // switch(m_currentIdentifier) {
  //   case "let":
  //     parseDeclaration();
  //     break;
  // }
}

void ASTBuilder::parseValueDeclaration() {
  m_lexer.swallowWhiteSpace();
}

}
}