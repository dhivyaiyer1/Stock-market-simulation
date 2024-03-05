#pragma once
#include "Test.h"
#include "LimitOrder.h"
#include "MarketOrder.h"
#include "CancelOrder.h"
#include "Person.h"

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
    ~BasicTests();
    void debug();
    
};