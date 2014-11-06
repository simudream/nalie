
#include "Lexer.h"
#include "Keyword.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

namespace AJSC {

bool Lexer::getNextToken() {
  if(m_currentIndex < m_source.length()) {
    m_currentToken = m_source.at(m_currentIndex);
    m_currentIndex++;
    return true;
  } else {
    m_currentToken = EOF_;
    return false;
  }
}

}