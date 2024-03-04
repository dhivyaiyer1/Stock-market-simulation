#pragma once
#include "Test.h"
#include "LimitOrder.h"
#include "Person.h"


class TestOrder : public Test
{
    private:
    Person* pn;
    LimitOrder* lo1;
    LimitOrder* lo2;
    LimitOrder* lo3;
    LimitOrder* lo4;
    std::string CompanyName;
    int shares;
    void buyOrder();
    void sellOrder();
    void cantBuyOrder();
    void cantSellOrder();

    public:
    TestOrder();
    ~TestOrder();
    void debug();
    void runAllTests();
};