#include <stdio.h>

void  __attribute__((no_instrument_function)) __cyg_profile_func_enter(void* func_address, void* call_site)
{
    printf("%s\n", __func__);
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_exit(void* func_address, void* call_site)
{
    printf("%s\n", __func__);
}

int __attribute__((no_instrument_function)) test_no_instrument(void) {
    printf("%s\n", __func__);
    return 0;
}

int test_instrument(void) {
    printf("%s\n", __func__);
    return 0;
}

int main(void)
{
    printf("%s\n", __func__);
    test_instrument();
    test_no_instrument();

    return 0;
}
