
#ifndef Lexer_h
#define Lexer_h

#include <string>

using namespace std;

namespace AJSC {
namespace Parser {

class Lexer {
public:
  int m_currentIndex;
  int m_maxLength;
  int m_currentToken;
  string m_source;

  Lexer(const std::string source);
  Lexer();

  bool getNextToken();
};

}
} // namespace AJSC::Parser

#endif // Lexer_h