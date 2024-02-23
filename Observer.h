#pragma once
#include <vector>

class Observer
{
    public:
    virtual void update(std::vector<void*> args) = 0;
};