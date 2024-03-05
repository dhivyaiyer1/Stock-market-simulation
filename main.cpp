#include "BasicTests.h"
#include "TestOrder.h"

int main() {
    BasicTests bt = BasicTests();
    bt.runAllTests();

    TestOrder to = TestOrder();
    to.runAllTests();
}
