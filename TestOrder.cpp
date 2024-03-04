#include "TestOrder.h"

TestOrder::TestOrder() : Test("Order tests")
{
    p1 = new Person("Person 1");
    p1_lo1 = new ("P1 Lo1", p1, rand_price(), rand_int(), rand_bool());
}

// buy order

// sell order

// person can't buy

// person can't sell