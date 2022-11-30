#include <iostream>
#include <dlfcn.h>

#define SO_A "./liba.so"

int
main(void)
{
   void *handle;
   char *error;
   int (*func)(int);
   int round = 5;

   while (round-- > 0) {
       std::cout << "round:" << round << std::endl;
       handle = dlopen(SO_A, RTLD_LAZY);
       if (!handle) {
           fprintf(stderr, "%s\n", dlerror());
           exit(EXIT_FAILURE);
       }

       dlerror();    /* Clear any existing error */

       func = (int (*)(int)) dlsym(handle, "test_a");

       error = dlerror();
       if (error != NULL) {
           fprintf(stderr, "%s\n", error);
           exit(EXIT_FAILURE);
       }

       func(round);

       dlclose(handle);
   }

   std::cout << "finish" << std::endl;

   return 0;
}

