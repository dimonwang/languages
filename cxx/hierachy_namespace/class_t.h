#include "test.h"
class TEST_C {
    // using namespace A;
    public:
        void ccc() {
            using namespace A;
            test();
        }
};
