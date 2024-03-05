#pragma once
#include "Test.h"

class LimitOrder;
class Person;

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
    void tests2run();

    public:
    TestOrder();
};