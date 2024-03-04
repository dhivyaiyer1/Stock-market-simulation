#pragma once
#include "Test.h"
#include "LimitOrder.h"
#include "Person.h"


class TestOrder : public Test
{
    private:
    Person p;
    LimitOrder* lo1;
    LimitOrder* lo2;
    LimitOrder* lo3;
    LimitOrder* lo4;

    public:
    TestOrder();
    ~TestOrder()
    void debug();
    void runAllTests();
};