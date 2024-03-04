#include "Test.h"

Test::Test(std::string name) 
    : name(name)
    , rd()
    , gen(rd())
    ,prev_test("")
{}

int Test::rand_int()
{
    return int_dist(gen);
}

double Test::rand_price()
{
    return dbl_dist(gen)/100.0;
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

void Test::addError(std::string test, std::string message)
{
    if (test != prev_test) 
    {
        errors<<"Test failed in "<<test<<":\n";
        prev_test = test;
    }
    errors<<"\t"<<message<<"\n";
}

void Test::finishTests()
{
    if (errors.str() == "")
    {
        std::cout<<name<<" passed\n";
    }
    else 
    {
        std::cout<<errors.str()<<"\n";
        debug();
    }
}