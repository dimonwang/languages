#include <stdio.h>

#if defined(__has_include) //&& __has_include("test.h")
#if __has_include("test.h")
#warning "test.h has included"
#else
#include "test.h"
#endif
#warning "__has_include defined"
#else
#warning "__has_include not defined"
#include "test.h"
#endif 

int main(void) {
    test();
    return 0;
}
