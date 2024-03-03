#include "BasicTests.h"

BasicTests::BasicTests() : Test("Basic Tests")
{
    pn = new Person("Test Person");
    lo = new LimitOrder("Test Limit Order", pn, rand_double(), rand_int(), rand_bool());
    mo = new MarketOrder("Test Market Order", pn, rand_int(), rand_bool());
    co = new CancelOrder("Test cancel order", lo);
}

void BasicTests::runAllTests()
{
    
    std::cout<<"Person:\n";
    pn->print();
    std::cout<<"Limit order:\n";
    lo->print();
    std::cout<<"Market order:\n";
    mo->print();
    std::cout<<"Cancel order:\n";
    co->print();
}

BasicTests::~BasicTests()
{
    delete pn;
    delete lo;
    delete mo;
    delete co;
}