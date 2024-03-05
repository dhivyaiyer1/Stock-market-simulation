#pragma once
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <sstream>

class TestObject;
// base class used for generating tests
class Test
{
    private:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::string prev_test;
    std::stringstream errors;
    std::string name;

    protected:
    std::vector<TestObject*> testObjects;
    Test(std::string name);
    ~Test();
    bool rand_bool();
    int rand_int(int low, int high);
    double rand_double(double low, double high);
    double rand_price(double low, double high);
    int rand_choice(int range);
    virtual void tests2run() = 0;
    void test(bool condition,std::string test,std::string message);

    public:
    void runAllTests();
    void debugAll();
};