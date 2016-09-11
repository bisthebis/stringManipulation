#include "catch.hpp"

#include <QVariant>
#include <QString>
#include <QDebug>
#include "lexer/tokentype.h"

struct VariantTest {
    VariantTest() : x(0), str("empty"){}
    VariantTest(int x, const QString& src) : x(x), str(src) {}
    int x;
    QString str;
};

Q_DECLARE_METATYPE(VariantTest)

TEST_CASE("QVariant works as expected", "[qvariant]")
{
    QVariant var = "42";
    CHECK(var.value<int>() == 42);
    CHECK(var.value<QString>() == QString("42"));

    var = TokenType::Identifier;
    CHECK(var.typeName() == QString("int")); //enums are int

    var.setValue(VariantTest(50, "Hi"));
    CHECK(var.value<VariantTest>().str == "Hi");

}
