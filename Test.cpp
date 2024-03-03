#include "Test.h"

Test::Test(std::string name) 
    : name(name)
    , rd()
    , gen(rd())
{}

int Test::rand_int()
{
    return int_dist(gen);
}

double Test::rand_double()
{
    return dbl_dist(gen);
}

int Test::rand_choice(int range)
{
    std::uniform_int_distribution<int> pos_choices(0, range-1);
    return pos_choices(gen);
}

bool Test::rand_bool()
{
    return rand_int() <= 50;
}