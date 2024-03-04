CXX = g++
CXXFLAGS = -std=c++2a -O0 -ggdb3

all: clean stockmarket

stockmarket: BasicTests CancelOrder LimitOrder main MarketOrder MatchingEngine Order OrderBook Person Test TestOrder
	$(CXX) $(CXXFLAGS) -o stockmarket BasicTests.o CancelOrder.o LimitOrder.o main.o MarketOrder.o MatchingEngine.o Order.o OrderBook.o Person.o Test.o TestOrder.o

BasicTests: BasicTests.cpp
	$(CXX) $(CXXFLAGS) -c BasicTests.cpp

CancelOrder: CancelOrder.cpp
	$(CXX) $(CXXFLAGS) -c CancelOrder.cpp

LimitOrder: LimitOrder.cpp
	$(CXX) $(CXXFLAGS) -c LimitOrder.cpp

main: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

MarketOrder: MarketOrder.cpp
	$(CXX) $(CXXFLAGS) -c MarketOrder.cpp

MatchingEngine: MatchingEngine.cpp
	$(CXX) $(CXXFLAGS) -c MatchingEngine.cpp

Order: Order.cpp
	$(CXX) $(CXXFLAGS) -c Order.cpp

OrderBook: OrderBook.cpp
	$(CXX) $(CXXFLAGS) -c OrderBook.cpp

Person: Person.cpp
	$(CXX) $(CXXFLAGS) -c Person.cpp

Test: Test.cpp
	$(CXX) $(CXXFLAGS) -c Test.cpp

TestOrder: TestOrder.cpp
	$(CXX) $(CXXFLAGS) -c TestOrder.cpp

clean:
	rm -rf *o stockmarket