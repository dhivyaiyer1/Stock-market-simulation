#pragma once
#include <string>
#include "MatchingEngine.h"
#include "Person.h"

class Company : public Person {
    public:
    MatchingEngine meng;

    Company(std::string n);
    void print();
};
