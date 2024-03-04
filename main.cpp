#include "BasicTests.h"
#include "TestOrder.h"

int main() {
    BasicTests bt = BasicTests();
    bt.runAllTests();
    bt.debug();

    TestOrder to = TestOrder();
    to.runAllTests();
    to.debug();
}
