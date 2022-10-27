#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

void sub_func()
{
    while(true) {
        sleep(1);
    }
}

int main() {
    std::thread t(sub_func);
    // t.start();
    t.join();
    std::cout << "done" << std::endl;

	return 0;
}
