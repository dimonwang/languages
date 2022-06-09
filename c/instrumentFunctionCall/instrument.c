#include <stdio.h>
#include "instrument.h"

#define INSTRUMENT_FILE_PATH "instrument.log"

static FILE *instrument_fd = NULL;
static int _flag = 0;

#define open_instrument_file()  \
    (instrument_fd = fopen(INSTRUMENT_FILE_PATH, "w"))

#define close_instrument_file()  \
     do{  \
     if (NULL != instrument_fd)  \
     {  \
     fclose(instrument_fd);  \
     instrument_fd = NULL; \
     }  \
     }while(0)


#define instrument_print(args, fmt...) \
     do{  \
     if (0 == _flag) \
     {  \
     break;  \
     }  \
     if (NULL == instrument_fd && NULL == open_instrument_file())  \
     {\
     printf("Err: Can not open output file.\n");  \
     break;  \
     }\
     fprintf(instrument_fd, args, ##fmt);  \
         fflush(instrument_fd);  \
     }while(0);

//enable, disable 閰嶅??逛娇鐢??锛屽湪鍏虫敞鐨勫嚱鏁颁笂娣诲姞
void  __attribute__((no_instrument_function)) enable_instrument( void )
{
    _flag = 1;
}
void  __attribute__((no_instrument_function)) disable_instrument( void )
{
    _flag = 0;
}
// 涓€鑸??鏄??鐢ㄤ笉鍒拌??ュ嚱鏁颁簡
void  __attribute__((no_instrument_function, destructor)) main_destructor( void )
{
    close_instrument_file();
}
void  __attribute__((no_instrument_function)) __cyg_profile_func_enter( void *func_addr, void *call_site )
{
    instrument_print("Enter, call_site:%p\n func_addr:%p\n", call_site, func_addr);
}
void  __attribute__((no_instrument_function)) __cyg_profile_func_exit( void *func_addr, void *call_site )
{
    instrument_print("Exit, call_site:%p\n func_addr:%p\n", call_site, func_addr);
}
