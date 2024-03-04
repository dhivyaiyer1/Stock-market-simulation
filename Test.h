#pragma once
#include <string>
#include <iostream>
#include <random>
#include <vector>
#include <sstream>

// base class used for generating tests
class Test
{
    private:
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> int_dist{1, 100};
    std::uniform_int_distribution<int> dbl_dist{1, 10000};
    std::string prev_test;

    protected:
    std::stringstream errors;
    std::string name;
    Test(std::string name);
    bool rand_bool();
    int rand_int();
    double rand_price();
    int rand_choice(int range);
    virtual void runAllTests() = 0;
    virtual void debug() = 0;
    void test(bool condition,std::string test,std::string message);
};