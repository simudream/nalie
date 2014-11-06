
#include "Lexer.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace AJSC {
namespace Parser {

bool Lexer::getNextToken() {
  m_currentIndex++;
  if(m_currentIndex < m_source.length()) {
    m_currentToken = m_source.at(m_currentIndex);
    return true;
  } else {
    return false;
  }
}

Lexer::Lexer() {}
Lexer::Lexer(const std::string source):
  m_currentIndex(0),
  m_source(source),
  m_maxLength(source.length()),
  m_currentToken(source.at(0)) {}

}
}