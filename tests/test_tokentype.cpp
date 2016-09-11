#include "catch.hpp"
#include "lexer/tokentype.h"


TEST_CASE ("Tokenizer recognises identifiers", "[tokentype]")
{
    //auto type = TokenType::getType(QStringLiteral("MyVar"));
    #define TYPE(str) TokenType::getType(QStringLiteral(str))

    CHECK(TYPE("MyVar") == TokenType::Identifier);
    CHECK(TYPE("_MyAttrib") == TokenType::Identifier);
    CHECK_FALSE(TYPE("01THISISNOTAVARIABLE") == TokenType::Identifier);

    CHECK(TYPE("056452") == TokenType::NumericLiteral);
    CHECK_FALSE(TYPE("+0x6789") == TokenType::NumericLiteral); //Plus must be either unary or binary operator
    CHECK(TYPE("0xFF") == TokenType::NumericLiteral);
    CHECK(TYPE("0b0100110") == TokenType::NumericLiteral);
    CHECK(TYPE("0.056448") == TokenType::NumericLiteral);
    CHECK_FALSE(TYPE("-3,1425423") == TokenType::NumericLiteral); // minus must be seen as unary operator




}
