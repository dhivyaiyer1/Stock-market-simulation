#include "Test.h"
#include "TestObject.h"

Test::Test(std::string name) 
    : name(name)
    , rd()
    , gen(rd())
    , prev_test("")
{}

int Test::rand_int(int low, int high)
{
    std::uniform_int_distribution<int> int_dist{low, high};
    return int_dist(gen);
}

double Test::rand_double(double low, double high)
{
    std::uniform_real_distribution<double> double_dist{low, high};
    return double_dist(gen);
}

double Test::rand_price(double low, double high)
{
    return rand_int(low*100, high*100)/100.0;
}

int Test::rand_choice(int range)
{
    return rand_int(0, range-1);
}

bool Test::rand_bool()
{
    std::uniform_int_distribution<int> bool_dist{0, 1};
    return bool_dist(gen);
}

void Test::test(bool condition,std::string test, std::string message)
{
    if (condition)
    {
        if (test != prev_test) 
        {
            errors<<"Test failed in "<<test<<":\n";
            prev_test = test;
        }
        errors<<"\t"<<message<<"\n";
    }
    
}

void Test::debugAll()
{
    for (TestObject* to : testObjects)
    {
        to->debug();
    }
}

void Test::runAllTests()
{
    std::cout<<"Running "<<name<<"\n";
    tests2run();
    if (errors.str() != "")
    {
        std::cout<<errors.str()<<"\n";
        std::cout<<"Debug output:\n";
        debugAll();   
    }
    else
    {
        std::cout<<name<<" passed\n";
    }   
}

Test::~Test()
{
    for (TestObject* to : testObjects)
    {
        delete to;
    }
}