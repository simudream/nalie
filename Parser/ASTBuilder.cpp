
#include "ASTBuilder.h"
#include "Lexer.h"
#include <string>

using namespace std;

namespace AJSC {

void Parser::ASTBuilder::parse(string script) {
  lexer = new Lexer(string);
}

}