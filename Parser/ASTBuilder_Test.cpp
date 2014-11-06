
#include <igloo/igloo_alt.h>

using namespace igloo;

#include "ASTBuilder.h"

Describe(ASTBuilder) {
  It(Should_set_source) {
    AJSC::Parser::ASTBuilder ast;
    ast.parse("test");
    Assert::That(ast.m_lexer.m_source, Equals("test"));
  }

  It(Should_set_max_length) {
    AJSC::Parser::ASTBuilder ast;
    ast.parse("test");
    Assert::That(ast.m_lexer.m_maxLength, Equals(4));
  }
};