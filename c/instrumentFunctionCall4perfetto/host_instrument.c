#include <stdio.h>
#include "instrument.h"

#define INSTRUMENT_FILE_PATH "instrument.log"

static int use_file = 1;
static FILE *instrument_fd = NULL;
static int _flag = 0;

#define open_instrument_file()                          \
    (instrument_fd = fopen(INSTRUMENT_FILE_PATH, "w"))

#define close_instrument_file()                         \
do {                                                    \
    if (NULL != instrument_fd)                          \
    {                                                   \
        fclose(instrument_fd);                          \
        instrument_fd = NULL;                           \
    }                                                   \
} while(0)


#define instrument_print(args, fmt...)                  \
do {                                                    \
    if (0 == _flag)                                     \
    {                                                   \
        break;                                          \
    }                                                   \
    if (use_file != 0 && NULL == instrument_fd && NULL == open_instrument_file())  \
    {                                                   \
        printf("Err: Can not open output file.\n");     \
        break;                                          \
    }                                                   \
    if (use_file == 0) {                                \
        printf(args, ##fmt);                            \
        break;                                          \
    }                                                   \
    fprintf(instrument_fd, args, ##fmt);                \
    fflush(instrument_fd);                              \
} while(0)

void  __attribute__((no_instrument_function)) enable_instrument( void )
{
    _flag = 1;
}
void  __attribute__((no_instrument_function)) disable_instrument( void )
{
    _flag = 0;
}

void  __attribute__((no_instrument_function, destructor)) main_destructor( void )
{
    close_instrument_file();
}


void  __attribute__((no_instrument_function)) __cyg_profile_func_enter( void *func_addr, void *call_site )
{
    // instrument_print("Enter, call_site:%x\n func_addr:%x\n", call_site, func_addr);
#define MAX_LEN 24
    if (_flag == 0) return;
    char virtualFuncAddr[MAX_LEN];
    memset(virtualFuncAddr, 0, MAX_LEN);
    snprintf(virtualFuncAddr, MAX_LEN-1, "%p", func_addr);

    char virtualCallerAddr[MAX_LEN];
    memset(virtualCallerAddr, 0, MAX_LEN);
    snprintf(virtualCallerAddr, MAX_LEN-1, "%p", call_site);

    printf("%s:%p, enter %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_enter,
            virtualFuncAddr, virtualCallerAddr);
#undef MAX_LEN
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_exit( void *func_addr, void *call_site )
{
    // instrument_print("Exit, call_site:%x\n func_addr:%x\n", call_site, func_addr);
#define MAX_LEN 24
    if (_flag == 0) return;
    char virtualFuncAddr[MAX_LEN];
    memset(virtualFuncAddr, 0, MAX_LEN);
    snprintf(virtualFuncAddr, MAX_LEN-1, "%p", func_addr);

    char virtualCallerAddr[MAX_LEN];
    memset(virtualCallerAddr, 0, MAX_LEN);
    snprintf(virtualCallerAddr, MAX_LEN-1, "%p", call_site);
    printf("%s:%p, exit %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_exit, 
            virtualFuncAddr, virtualCallerAddr);
#undef MAX_LEN
}
