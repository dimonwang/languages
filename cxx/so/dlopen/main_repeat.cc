#include <iostream>
#include <dlfcn.h>

#define SO_A "./liba.so"

int
main(void)
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

   void *handle2;
   char *error2;
   int (*func2)(int);
   handle2 = dlopen(SO_A, RTLD_LAZY);
   if (!handle2) {
       fprintf(stderr, "%s\n", dlerror());
       return 3;
   }

   dlerror();    /* Clear any existing error */

   func2 = (int (*)(int)) dlsym(handle2, "test_a");

   error2 = dlerror();
   if (error2 != NULL) {
       fprintf(stderr, "%s\n", error2);
       return 4;
   }

   std::cout << "set to 200" << std::endl;
   func2(200);
   std::cout << "set 200" << std::endl;

   dlclose(handle2);
   dlclose(handle);

   return 0;
}

