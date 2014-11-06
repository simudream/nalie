
#include "Lexer.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace AJSC {
namespace Parser {

bool Lexer::getNextToken() {
  if(m_currentIndex < m_source.length()) {
    m_currentToken = m_source.at(m_currentIndex);
    m_currentIndex++;
    return true;
  } else {
    return false;
  }
}

Lexer::Lexer() {}
Lexer::Lexer(const std::string source):
  m_source(source),
  m_maxLength(source.length()) {}

}
}