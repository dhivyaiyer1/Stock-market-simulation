#include "OrderBook.h"
#include <iostream>

OrderBook::~OrderBook() {
	for (int i=0; i<orders.size(); i++) {
		for (int j=0; j<orders[i].size(); j++) {
			if (orders[i][j]!=NULL) {
				delete orders[i][j];
			}
		}
	}
}

void OrderBook::updateIndex(int i) {
    double p = orders[i][0]->price;
    if (map.contains(p)) {
        map[p] = i;
    }
}

void OrderBook::swap(int x, int y) {
    std::vector<LimitOrder*> temp = orders[x];
    orders[x]=orders[y];
    orders[y]=temp;
    updateIndex(x);
    updateIndex(y);
}

int OrderBook::parent(int i) {
    return (i-1)/2;
}

int OrderBook::left(int i) {
    return (2*i +1);
}

int OrderBook::right(int i) {
    return (2*i +2);
}

LimitOrder* OrderBook::peek() {
    return orders[0][0];
}

bool OrderBook::lessThan(int i, int j) {
    if (buy) {
        return orders[i][0]->price>orders[j][0]->price;
    } else {
        return orders[i][0]->price<orders[j][0]->price;
    }
}

bool OrderBook::greaterThan(int i, int j) {
    if (buy) {
        return orders[i][0]->price<orders[j][0]->price;
    } else {
        return orders[i][0]->price>orders[j][0]->price;
    }
}

void OrderBook::insert(LimitOrder* lo) {
    if (lo->buy!=buy) {
        std::cout<<"Error: buy is not the same\n";
        return;
    }
    //int f = map.contains(lo->price);
    if (!(map.contains(lo->price))) {
        int i = orders.size();
        map.insert({lo->price,i});
        orders.push_back({lo});
        updateIndex(i);
        while (i != 0  && greaterThan(parent(i),i)) {
            swap(i, parent(i));
            i=parent(i);
        }
    } else {
        orders[map[lo->price]].push_back(lo);
    }
}

void OrderBook::printAllOrders() {
    std::string buy_sell = buy ? "Buy" : "Sell";
    std::cout<<buy_sell<<" prices:\n";
    for (auto i : map)
    {
        std::cout<<i.first<<" ";
    }
    std::cout<<"\n";
    std::cout<<buy_sell<<" orders:\n";
    for (int i=0; i<orders.size(); i++) {
        for (int j=0; j<orders[i].size(); j++) {
            std::cout<<"("<<orders[i][j]->orderName<<", "<<orders[i][j]->price<<") ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void OrderBook::heapify(int i) {
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if (l<orders.size() && lessThan(l,i)) {
        smallest=l;
    }
    if (r<orders.size() && lessThan(r,smallest)) {
        smallest=r;
    }
    if (smallest != i) {
        swap(i, smallest);
        heapify(smallest);
    }
}

void OrderBook::poll() {
    if (orders.size()<=0) {
        std::cout<<"Error: OrderBook is empty\n";
    }
    LimitOrder* root=orders[0][0];
    orders[0].erase(orders[0].begin());
    if (orders[0].size()==0) {
        orders[0] = orders.back();
        updateIndex(0);
        orders.pop_back();
        heapify(0);
        map.erase(root->price);
    }
}

void OrderBook::remove(int i) {
    while (i!=0 && greaterThan(parent(i),i)) {
        swap(i,parent(i));
        i = parent(i);
    }
}

void OrderBook::cancel(LimitOrder* lo) {
    std::cout<<"Canceling "<<lo->orderName<<"\n";
    if (!(map.contains(lo->price))) {
        std::cout<<lo->orderName<<" is not in this orderbook\n";
        return;
    }
    int i = map[lo->price];
    if (orders[i].size()>1) {
        int j=0;
        while (orders[i][j]!=lo) {
            j++;
        }
        orders[i].erase(orders[i].begin()+j);
    } else {
        map.erase(lo->price);
        lo->price = orders[0][0]->price-1+2*buy;
        remove(i);
        poll();
    }
}

void OrderBook::changePrice(LimitOrder* lo, double newPrice) {
    cancel(lo);
    lo->price=newPrice;
    insert(lo);
}

bool OrderBook::isEmpty() {
    return orders.size()==0;
}
