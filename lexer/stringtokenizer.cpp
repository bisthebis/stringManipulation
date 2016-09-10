#include "stringtokenizer.h"

QStringList StringTokenizer::tokenize(QString src)
{
    static const QRegularExpression exp("(([a-zA-Z_][a-zA-Z0-9_]*)|([1-9]+))");
    auto matches = exp.globalMatch(src);
    QStringList list;
    while (matches.hasNext())
    {
        list << matches.next().captured(0);
    }

    return list;
}
