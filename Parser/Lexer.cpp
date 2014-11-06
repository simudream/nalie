
#include "Lexer.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace AJSC {
namespace Parser {

char Lexer::getToken() {
  if(m_currentIndex < m_source.length()) {
    char currentToken = m_source.at(m_currentIndex);
    m_currentIndex++;
    m_column++;
    if(m_newline) {
      m_newline = false;
      m_column = 1;
      m_line++;
    }
    if(currentToken == '\n') {
      m_newline = true;
    }
    return currentToken;
  } else {
    return EOF;
  }
}

Lexer::Lexer() {}
Lexer::Lexer(const std::string source):
  m_currentIndex(0),
  m_line(1),
  m_column(0),
  m_newline(false),
  m_source(source),
  m_maxLength(source.length()),
  m_currentToken(source.at(0)) {}

}
}