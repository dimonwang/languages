#include <iostream>
#include "test.h"
#include "test_2.h"
#include "class_t.h"

int main(void) {
    B::A::test();
    A::test();
    TEST_C c;
    c.ccc();
    return 0;
}
