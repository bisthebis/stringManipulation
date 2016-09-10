#include "catch.hpp"

#include <QString>
#include <QRegularExpression>

TEST_CASE ("QRegularExpression work on basic data", "[qregularexpression]")
{
    #define ASSERT_MATCH(str) CHECK(regex.match((str)).hasMatch())
    #define ASSERT_NO_MATCH(str) CHECK_FALSE(regex.match((str)).hasMatch())

    QRegularExpression regex("^[a-z]+$");
    ASSERT_MATCH("agndfhiornbqhoif");
    ASSERT_MATCH("a");
    ASSERT_NO_MATCH("");
    ASSERT_NO_MATCH("azerZt");
    ASSERT_NO_MATCH(" azerty ");

    regex.setPattern("^\\s*\\d+\\s*$");
    ASSERT_MATCH("1324589");
    ASSERT_MATCH(" 1551458989 ");
    ASSERT_NO_MATCH("155145 8989");

    regex.setPattern("s*[-\\+]?\\d+([,\\.]\\d+)*");
    ASSERT_MATCH("   +7895210 ");
    ASSERT_MATCH("  \n\n -572.3348");


    #undef ASSERT_MATCH
}

TEST_CASE ("QRegularExpression work with capturing", "[qregularexpression]")
{


    QRegularExpression regex("^([a-zA-Z][a-zA-Z0-9_\\.]*[a-zA-Z0-9])@([a-zA-Z]+\\.[a-zA-Z]+)");
    auto match = regex.match("bism25@hotmail.com");
    CHECK(match.captured(1) == "bism25");
    CHECK(match.captured(2) == "hotmail.com");
}
