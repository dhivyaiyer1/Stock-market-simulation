#include "BasicTests.h"
#include "LimitOrder.h"
#include "MarketOrder.h"
#include "CancelOrder.h"
#include "Person.h"

BasicTests::BasicTests() 
    : Test("Basic Tests")
{
    pn = new Person("Test Person");
    lo1 = new LimitOrder("Test Limit Order", pn, rand_price(1,100), rand_int(1,100), rand_bool());
    mo = new MarketOrder("Test Market Order", pn, rand_int(1,100), rand_bool());
    lo2 = new LimitOrder(mo, rand_price(1,100));
    co = new CancelOrder("Test cancel order", lo1);
    testObjects.push_back(pn);
    testObjects.push_back(lo1);
    testObjects.push_back(mo);
    testObjects.push_back(lo2);
    testObjects.push_back(co);
}

// initializes a cancel order from a limit order
void BasicTests::InitializeCancel()
{
    std::string test_name = "BasicTests::InitializeCancel()";
    test(co->buy != lo1->buy,test_name,"CancelOrder->buy != LimitOrder->buy");
    test(co->quantity != lo1->quantity, test_name,"CancelOrder->quantity != LimitOrder->quantity");
    test(co->person != lo1->person,test_name,"CancelOrder->person != LimitOrder->person");
}

// initializes a Limit order from a market order
void BasicTests::Market2LimitOrder()
{
    std::string test_name = "BasicTests::Market2LimitOrder()";
    test(mo->buy != lo2->buy,test_name,"MarketOrder->buy != LimitOrder->buy");
    test(mo->quantity != lo2->quantity,test_name,"MarketOrder->quantity != LimitOrder->quantity");
    test(mo->person != lo2->person,test_name,"MarketOrder->person != LimitOrder->person");
    test(mo->orderName != lo2->orderName,test_name,"MarketOrder->orderName != LimitOrder->orderName");
}

void BasicTests::tests2run()
{
    InitializeCancel();
    Market2LimitOrder();
}