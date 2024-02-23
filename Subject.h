#pragma once

class Observer;

class Subject
{
    public:
    virtual void registerObserver(Observer& ob) = 0;
    virtual void unregisterObserver(Observer& ob) = 0;
    virtual void notifyAllObservers() = 0;
};