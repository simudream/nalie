
#include <string>
#include <cstring>
#include <iostream>
#include "Lexer.h"
#include "Identifiers.h"

using namespace std;

namespace AJSC {
namespace Parser {

Lexer::Lexer() {}
Lexer::Lexer(const string source):
  m_currentIndex(0),
  m_line(1),
  m_lineString(""),
  m_column(0),
  m_newline(false),
  m_source(source),
  m_maxLength(source.length()),
  m_currentToken(source.at(0)) {}

char Lexer::getToken() {
  if(m_source.length() == 0) {
    throw invalid_argument("Can not get next token if source is not set.");
  }

  if(m_currentIndex < m_source.length()) {
    m_currentToken = m_source.at(m_currentIndex);
    m_lineString += m_currentToken;
    m_currentIndex++;
    m_column++;
    if(m_newline) {
      m_newline = false;
      m_column = 1;
      m_line++;
    }
    if(m_currentToken == '\n') {
      m_newline = true;
      m_lineString = "";
    }
    return m_currentToken;
  } else {
    return Identifier::EOF_;
  }
}

string Lexer::getLine() {
  return m_lineString;
}

void Lexer::swallowWhiteSpace() {
  while(isspace(m_currentToken)) {
    m_currentToken = getToken();
  }
}

}
}