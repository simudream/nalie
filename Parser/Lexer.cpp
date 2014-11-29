
#include <string>
#include <cstring>
#include <iostream>
#include "Lexer.h"
#include "Identifiers.h"

namespace AJSC {
namespace Parser {

Lexer::Lexer() {}
Lexer::Lexer(const std::string source):
  m_currentIndex(0),
  m_line(1),
  m_column(0),
  m_newline(false),
  m_source(source),
  m_maxLength(source.length()),
  m_currentToken(source.at(0)) {}

char Lexer::getToken() {
  if(m_source.length() == 0) {
    throw std::invalid_argument("Can not get next token if source is not set.");
  }

  if(m_currentIndex < m_source.length()) {
    m_currentToken = m_source.at(m_currentIndex);
    m_currentIndex++;
    m_column++;
    if(m_newline) {
      m_newline = false;
      m_column = 1;
      m_line++;
    }
    if(m_currentToken == '\n') {
      m_newline = true;
    }
    return m_currentToken;
  } else {
    return Identifier::EOF_;
  }
}

void Lexer::swallowWhiteSpace() {
  while(isspace(m_currentToken)) {
    m_currentToken = getToken();
  }
}

}
}