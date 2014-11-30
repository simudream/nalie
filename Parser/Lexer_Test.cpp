
#include <igloo/igloo_alt.h>
#include <string>
#include "Lexer.h"
#include "Identifiers.h"

using namespace igloo;

Describe(Lexer) {
  Describe(getToken) {
    It(should_set_source) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_source, Equals("test"));
    }

    It(should_set_current_index_to_0) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_currentIndex, Equals(0));
    }

    It(should_set_current_token_first_token) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_currentToken, Equals('t'));
    }

    It(should_set_current_token_the_current_indexed_token) {
      AJSC::Parser::Lexer lexer("test");
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_currentToken, Equals('e'));
    }

    It(should_set_line_number_to_1) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_line, Equals(1));
    }

    It(should_set_column_number_to_0) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_column, Equals(0));
    }

    It(should_set_max_length) {
      AJSC::Parser::Lexer lexer("test");
      Assert::That(lexer.m_maxLength, Equals(4));
    }

    It(should_be_able_to_set_current_token) {
      AJSC::Parser::Lexer lexer("test");
      int currentToken = lexer.getToken();
      Assert::That(currentToken, Equals('t'));
    }

    It(should_be_able_to_get_token_and_increment_index) {
      AJSC::Parser::Lexer lexer("test");
      char currentToken = lexer.getToken();
      Assert::That(lexer.m_currentIndex, Equals(1));
      Assert::That(currentToken, Equals('t'));
    }

    It(should_be_able_to_return_EOF_whenever_the_string_is_ended) {
      AJSC::Parser::Lexer lexer("test");
      lexer.getToken();
      lexer.getToken();
      lexer.getToken();
      lexer.getToken();
      char currentToken = lexer.getToken();
      Assert::That(currentToken, Equals(Identifier::EOF_));
    }

    It(should_be_able_to_set_line_number_to_current_row_number_whenever_it_encounter_new_line) {
      AJSC::Parser::Lexer lexer("t\nest");
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_line, Equals(1));
    }

    It(should_increment_line_number_after_newline_encounter) {
      AJSC::Parser::Lexer lexer("t\nest");
      lexer.getToken();
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_line, Equals(2));
    }

    It(should_be_able_to_set_column_number) {
      AJSC::Parser::Lexer lexer("t\nest");
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_column, Equals(2));
    }

    It(should_be_able_to_set_column_number_to_1_after_new_line_encounter) {
      AJSC::Parser::Lexer lexer("t\nest");
      lexer.getToken();
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_column, Equals(1));
    }

    It(should_be_able_to_set_line_string) {
      AJSC::Parser::Lexer lexer("t\nest");
      lexer.getToken();
      Assert::That(lexer.m_lineString, Equals("t"));
      lexer.getToken();
      lexer.getToken();
      lexer.getToken();
      Assert::That(lexer.m_lineString, Equals("es"));
    }

    It(should_throw_an_error_if_source_is_not_set) {
      AJSC::Parser::Lexer lexer;
      AssertThrows(std::logic_error, lexer.getToken());
      Assert::That(LastException<std::logic_error>().what(), Is().Containing("Can not get next token if source is not set"));
    }
  };

  Describe(swallowWhiteSpace) {
    It(should_swallow_white_space_when_standing_on_white_space) {
      AJSC::Parser::Lexer lexer("  test");
      lexer.swallowWhiteSpace();
      Assert::That(lexer.m_currentToken, Equals('t'));
      Assert::That(lexer.m_column, Equals(3));
    }

    It(should_swallow_white_space_when_not_standing_on_white_space) {
      AJSC::Parser::Lexer lexer("  ");
      lexer.swallowWhiteSpace();
      Assert::That(lexer.m_currentToken, Equals(Identifier::EOF_));
    }
  };
};