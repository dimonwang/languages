#include <iostream>
#include <exception>

int main() {
    int nloop = 10000;

    do {
        try {
            throw ("1");
        } catch(const char *in) {
            // printf("get Exception:%s\n", e.what());
            // printf("get Exception:%s\n", in);
        }
    } while (--nloop > 0);

	return 0;
}
