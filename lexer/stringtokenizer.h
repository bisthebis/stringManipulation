#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include <QRegularExpression>
#include <QStringList>
#include <QVariant>

#include "lexer/tokentype.h"


class StringTokenizer
{
    public:
        static QStringList tokenize(QString src);
        static QList<Token> scan(QString src);

};

#endif // STRINGTOKENIZER_H
