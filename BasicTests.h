#pragma once
#include "Test.h"
#include "LimitOrder.h"
#include "MarketOrder.h"
#include "CancelOrder.h"
#include "Person.h"

class BasicTests : public Test
{
    private:
    LimitOrder* lo;
    MarketOrder* mo;
    CancelOrder* co;
    Person* pn;

    public:
    BasicTests();
    ~BasicTests();
    void runAllTests();
};