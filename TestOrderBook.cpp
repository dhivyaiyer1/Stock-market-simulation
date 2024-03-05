#include "TestOrderBook.h"
#include "OrderBook.h"

TestOrderBook::TestOrderBook
    : Test("OrderBook Test")
    , buy(rand_bool())
    , top_price(0)
{
    ob = new OrderBook(buy);
    
}