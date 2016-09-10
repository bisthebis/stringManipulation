#ifndef STRINGTOKENIZER_H
#define STRINGTOKENIZER_H

#include <QRegularExpression>
#include <QStringList>

class StringTokenizer
{
    public:
        static QStringList tokenize(QString src);

};

#endif // STRINGTOKENIZER_H
