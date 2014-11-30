
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

  if(m_currentIdentifier == "let") {
    parseLetDeclaration();
  }
}

void ASTBuilder::parseLetDeclaration() {
  m_lexer.swallowWhiteSpace();

  if(!isalnum(m_lexer.m_currentToken)) {
    throw invalid_argument("Expected a variable name after let keyword in " + m_lexer.getLine());
  }
}

}
}