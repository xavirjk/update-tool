#include <QtTest>

// add necessary includes here

class updator : public QObject
{
    Q_OBJECT

public:
    updator();
    ~updator();

private slots:
    void test_case1();

};

updator::updator()
{

}

updator::~updator()
{

}

void updator::test_case1()
{

}

QTEST_APPLESS_MAIN(updator)

#include "tst_updator.moc"
