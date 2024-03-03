#pragma once
#include <string>
#include <iostream>
#include <random>
#include <vector>

// base class used for generating tests
class Test
{
    private:
    std::string name;
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<int> int_dist{1, 100};
    std::uniform_real_distribution<double> dbl_dist{0.01, 100.0};

    protected:
    Test(std::string name);
    bool rand_bool();
    int rand_int();
    double rand_double();
    int rand_choice(int range);
    virtual void runAllTests() = 0;
};