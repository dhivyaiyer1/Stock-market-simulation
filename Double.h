#pragma once
#include "Key.h"
#include <cmath>

    class Double : public Key<double>
    {
        public:
        double num;
        Double(double p) : num(p) {};

        int hash()
        {
            return round(num);
        };

        double value()
        {
            return num;
        };

        bool equals(Key* box)
        {
            return num==box->value();
        };
    };