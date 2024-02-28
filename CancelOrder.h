#pragma once
#include "LimitOrder.h"

class CancelOrder : public Order
{
    private:
    LimitOrder* order;

    public:
    CancelOrder(std::string on,LimitOrder* order);
    ~CancelOrder()
    {
        std::cout<<"Deleting "<<orderName<<"\n";
    };
    void print();
};