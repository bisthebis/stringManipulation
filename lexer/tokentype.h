#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <QString>
#include <QVariant>

struct Token;

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
        static Token analyseToken(QString token);


};


struct Token {

    TokenType::Type type;
    QVariant value;

    //TokenType (TokenType::Type t, QVariant v) : type(t), value(v) {}


    QString toString() const;
};


#endif // TOKENTYPE_H
