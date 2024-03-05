#include "TestOrder.h"
#include "LimitOrder.h"
#include "Person.h"

TestOrder::TestOrder() 
    : Test("Order tests")
    , CompanyName("Test company")
    , shares(rand_int(1,10))
{
    pn = new Person("Person");
    lo1 = new LimitOrder("Order 1", pn, rand_price(1,100), rand_int(11,110), true);
    lo2 = new LimitOrder("Order 2", pn, rand_price(1000,1100), rand_int(11,100), true);
    lo3 = new LimitOrder("Order 3", pn, rand_price(1,100), lo1->quantity-5, false);
    lo4 = new LimitOrder("Order 4", pn, rand_price(1,100), rand_int(101,200), false);
    testObjects.push_back(pn);
    testObjects.push_back(lo1);
    testObjects.push_back(lo2);
    testObjects.push_back(lo3);
    testObjects.push_back(lo4);
}

// buy order
void TestOrder::buyOrder()
{
    std::string test_name = "TestOrder::buyOrder()";
    int prev_quantity = lo1->quantity;
    //double total_value = shares*lo1->price;
    bool success = lo1->execute(CompanyName, shares, lo1->price);
    test(!success,test_name, "Buy order failed when it should succeed");
    test(!pn->canSell(CompanyName, shares),test_name, "Person can't sell what they just bought");
    test(lo1->quantity != prev_quantity-shares,test_name, "Order quantity not updated properly");
}

// sell order
void TestOrder::sellOrder()
{
    std::string test_name = "TestOrder::sellOrder()";
    int prev_quantity = lo3->quantity;
    double value = lo3->price;
    bool success = lo3->execute(CompanyName, shares, value);
    test(!success,test_name, "Sell order failed when it should succeed");
    test(!pn->canBuy(shares, value),test_name, "Person can't buy what they just sold");
    test(lo3->quantity != prev_quantity-shares,test_name, "Order quantity not updated properly");
}

// person can't buy
void TestOrder::cantBuyOrder()
{
    std::string test_name = "TestOrder::cantBuyOrder()";
    test(lo2->execute(CompanyName, lo2->quantity, lo2->price),test_name, "Buy order succeeded when it should fail");
}

// person can't sell
void TestOrder::cantSellOrder()
{
    std::string test_name = "TestOrder::cantSellOrder()";
    test(lo4->execute(CompanyName, lo4->quantity, lo4->price), test_name, "Sell order succeeded when there are too many shares to sell");
    test(lo3->execute("some other company", 1, lo4->price), test_name, "Sell order succeeded with wrong company name");
}

void TestOrder::tests2run()
{
    buyOrder();
    sellOrder();
    cantBuyOrder();
    cantSellOrder();
}