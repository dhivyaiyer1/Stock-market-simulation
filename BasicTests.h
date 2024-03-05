#pragma once
#include "Test.h"

class LimitOrder;
class MarketOrder;
class CancelOrder;
class Person;

class BasicTests : public Test
{
    private:
    LimitOrder* lo1;
    LimitOrder* lo2;
    MarketOrder* mo;
    CancelOrder* co;
    Person* pn;
    void InitializeCancel();
    void Market2LimitOrder();
    void tests2run();

    public:
    BasicTests();
};