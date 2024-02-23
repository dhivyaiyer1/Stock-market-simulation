#include "Company.h"
#include "Person.h"
#include <iostream>

Company::Company(std::string n)
    : Person(n)
{
    shares = 10000;
}

void Company::print() 
{
    Person::printInfo();
	meng.print();
}
