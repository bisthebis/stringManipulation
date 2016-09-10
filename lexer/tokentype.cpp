#include "tokentype.h"
#include <QString>
#include <QRegularExpression>

TokenType::Type TokenType::getType(QString src)
{
    static const QRegularExpression isIdentifier("^[a-zA-Z_][a-zA-Z0-9_]*$");
    static const QRegularExpression isIntegerLiteral("^[-\\+]?[0-9]+$");
    static const QRegularExpression isHexadecimalLiteral("^[-\\+]?0x[0-9A-F]+$");
    static const QRegularExpression isBinaryLiteral("^[-\\+]?0b[01]+");
    static const QRegularExpression isFloatingLiteral("^[-\\+]?\\d+([,\\.]\\d+)");

    if (isIdentifier.match(src).hasMatch()
            && !isHexadecimalLiteral.match(src).hasMatch()
            && !isBinaryLiteral.match(src).hasMatch()
            )
        return Identifier;
    else if (isIntegerLiteral.match(src).hasMatch()
             || isHexadecimalLiteral.match(src).hasMatch()
             || isBinaryLiteral.match(src).hasMatch()
             || isFloatingLiteral.match(src).hasMatch())
        return NumericLiteral;
    else
        return Unknown;
}
