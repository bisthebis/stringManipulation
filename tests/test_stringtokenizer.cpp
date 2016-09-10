#include "catch.hpp"

#include "lexer/stringtokenizer.h"
#include "lexer/tokentype.h"
#include <QDebug>

TEST_CASE ("Splitting is correct", "[stringtokenizer]")
{
    QString input = "_azerty yolo23 CONNARD 534";
    auto tokens = StringTokenizer::tokenize(input);
    for (auto token : tokens)
    {
        //token.chop(1);
        //token.remove(0, 1);
        qDebug() << "Token : " << token << "and type : " << TokenType::getType(token) << ". Lentgh : " << token.length();
    }


}
