all: clean stockmarket

stockmarket: Company LimitOrder MarketOrder CancelOrder MatchingEngine Order OrderBook Person main
	g++ -std=c++2a -O0 -ggdb3 -o stockmarket Company.o LimitOrder.o MarketOrder.o CancelOrder.o MatchingEngine.o Order.o OrderBook.o Person.o main.o

LimitOrder: LimitOrder.cpp
	g++ -O0 -ggdb3 -c -std=c++2a LimitOrder.cpp

MarketOrder: MarketOrder.cpp
	g++ -O0 -ggdb3 -c -std=c++2a MarketOrder.cpp

CancelOrder: CancelOrder.cpp
	g++ -O0 -ggdb3 -c -std=c++2a CancelOrder.cpp

MatchingEngine: MatchingEngine.cpp
	g++ -O0 -ggdb3 -c -std=c++2a MatchingEngine.cpp

Order: Order.cpp
	g++ -O0 -ggdb3 -c -std=c++2a Order.cpp

OrderBook: OrderBook.cpp
	g++ -O0 -ggdb3 -c -std=c++2a OrderBook.cpp

Person: Person.cpp
	g++ -O0 -ggdb3 -c -std=c++2a Person.cpp

main: main.cpp
	g++ -O0 -ggdb3 -c -std=c++2a main.cpp

clean:
	rm -rf *o stockmarket