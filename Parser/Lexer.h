
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
  int m_line;
  int m_column;
  bool m_newline;
  string m_source;

  Lexer(const std::string source);
  Lexer();

  char getToken();
};

}
} // namespace AJSC::Parser

#endif // Lexer_h