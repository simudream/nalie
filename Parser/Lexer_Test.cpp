
#include "Lexer.h"
#include <igloo/igloo_alt.h>
#include <string>

using namespace igloo;


Describe(Lexer) {
  It(should_set_source) {
    AJSC::Parser::Lexer lexer("test");
    Assert::That(lexer.m_source, Equals("test"));
  }

  It(should_set_current_index_to_0) {
    AJSC::Parser::Lexer lexer("test");
    Assert::That(lexer.m_currentIndex, Equals(0));
  }

  It(should_set_max_length) {
    AJSC::Parser::Lexer lexer("test");
    Assert::That(lexer.m_maxLength, Equals(4));
  }

  It(should_be_able_to_set_current_token) {
    AJSC::Parser::Lexer lexer("test");
    Assert::That(lexer.m_currentToken, Equals('t'));
  }

  It(should_be_able_to_get_next_token) {
    AJSC::Parser::Lexer lexer("test");
    lexer.getNextToken();
    Assert::That(lexer.m_currentIndex, Equals(1));
    Assert::That(lexer.m_currentToken, Equals('e'));
  }

  It(should_return_eof_when_end_of_file) {
    AJSC::Parser::Lexer lexer("te");
    lexer.getNextToken();
    lexer.getNextToken();
    lexer.getNextToken();
    Assert::That(lexer.m_currentToken, Equals(EOF));
  }
};