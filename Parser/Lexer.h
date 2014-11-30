
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
  char m_currentToken;
  int m_line;
  string m_lineString;
  int m_column;
  bool m_newline;
  string m_source;

  Lexer(const std::string source);
  Lexer();

  // Get next token from source string.
  char getToken();

  // Swallows white space. It will stop lexing tokens when it encounters
  // any non-whitespace characters
  void swallowWhiteSpace();

  // Get current lexing line
  string getLine();
};

}
} // namespace AJSC::Parser

#endif // Lexer_h