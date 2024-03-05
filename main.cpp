#include "BasicTests.h"
#include "TestOrder.h"

int main() {
    BasicTests bt = BasicTests();
    bt.runAllTests();
    bt.debugAll();

    TestOrder to = TestOrder();
    to.runAllTests();
    to.debugAll();
}
