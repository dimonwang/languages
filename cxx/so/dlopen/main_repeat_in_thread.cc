#include <iostream>
#include <dlfcn.h>
#include <thread>
#include <unistd.h>

#define SO_A "./liba.so"

int
test_thread(void)
{
   void *handle;
   char *error;
   int (*func)(int);

   handle = dlopen(SO_A, RTLD_LAZY);
   if (!handle) {
       fprintf(stderr, "%s\n", dlerror());
       return 1;
   }

   dlerror();    /* Clear any existing error */

   func = (int (*)(int)) dlsym(handle, "test_a");

   error = dlerror();
   if (error != NULL) {
       fprintf(stderr, "%s\n", error);
       return 2;
   }

   func(100);

   dlclose(handle);

   sleep(10);
   return 0;
}

int main(void)
{
    std::thread a(test_thread);
    std::thread b(test_thread);
    a.join();
    b.join();

    return 0;
}
