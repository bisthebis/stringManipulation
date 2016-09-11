#include "catch.hpp"

#include "lexer/stringtokenizer.h"
#include "lexer/tokentype.h"
#include <QDebug>

TEST_CASE ("Splitting is correct", "[stringtokenizer]")
{
    QString input = "_MyVariable = 450 + (THIS_IS_A_CONSTANT/0b11) - 0xFF*789.32; \n Result = func(x, y);";
    static const QStringList expected {"_azerty", "yolo23", "CONNARD", "534"};

    auto tokens = StringTokenizer::tokenize(input);

    CHECK (tokens == expected);
    if (tokens != expected)
        qDebug() << tokens;




}
