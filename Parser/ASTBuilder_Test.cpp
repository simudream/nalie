
#include "ASTBuilder.h"
#include <igloo/igloo_alt.h>
#include <string>

using namespace igloo;

Describe(ASTBuilder) {
  It(should_set_current_identifier) {
    AJSC::Parser::ASTBuilder ASTBuilder_;
    ASTBuilder_.parse("let test");
    Assert::That(ASTBuilder_.m_currentIdentifier, Equals("let"));
  }
};