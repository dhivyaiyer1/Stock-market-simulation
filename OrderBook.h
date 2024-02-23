#pragma once
#include <vector>
#include "LimitOrder.h"
#include <unordered_map>

class LimitOrder;

using namespace std;

class OrderBook {
    private:
    vector<vector<LimitOrder*>> orders;
    bool buy;
    void swap(int x, int y);
    static int parent (int i);
    static int left(int i);
    static int right (int i);
    void heapify(int i);
    void updateIndex(int i);
    void remove(int i);
    bool lessThan(int i, int j);
    bool greaterThan(int i, int j);

    public:
    unordered_map<double,int> map;
    OrderBook(bool b) : buy(b) {};
	~OrderBook();
    LimitOrder* peek();
    void poll();
    void cancel(LimitOrder* lo);
    void insert(LimitOrder* lo);
    void printAllOrders();
    void changePrice(LimitOrder* lo, double newPrice);
    bool isEmpty();
};