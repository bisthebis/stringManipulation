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
        static const QString& toString(Type t) {
            static const QString sIdentifier = "Identifier";
            static const QString sNumericLiteral = "NumericLiteral";
            static const QString sUnknown = "Unknown";

            switch (t) {
            case Identifier:
                return sIdentifier;
                break;
            case NumericLiteral:
                return sNumericLiteral;
                break;

            default:
                return sUnknown;
                break;
            }
        }

        static Type getType(QString src);


};

#endif // TOKENTYPE_H
