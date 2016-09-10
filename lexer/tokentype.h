#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <QString>

class TokenType
{
    public:
        enum Type {
            Identifier,
            NumericLiteral,
            Unknown
        };

        static Type getType(QString src);


};

#endif // TOKENTYPE_H
