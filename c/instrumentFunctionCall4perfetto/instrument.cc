#include <stdio.h>
#include "instrument.h"
#include "perfetto.h"

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


PERFETTO_DEFINE_CATEGORIES(
        perfetto::Category(MINIGUI_TRACE_CATEGORY)
        .SetDescription("minigui"));

PERFETTO_TRACK_EVENT_STATIC_STORAGE();

void initialize0() {
    perfetto::TracingInitArgs args;
    args.backends |= perfetto::kInProcessBackend;
    args.backends |= perfetto::kSystemBackend;

    perfetto::Tracing::Initialize(args);
    perfetto::TrackEvent::Register();
}



#ifdef __cplusplus
extern "C" {
#endif

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

void initialize() {
    initialize0();
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_enter( void *func_addr, void *call_site )
{
    // instrument_print("Enter, call_site:%x\n func_addr:%x\n", call_site, func_addr);
#define MAX_LEN 17
    char effectiveAddr[MAX_LEN];
    memset(effectiveAddr, 0, MAX_LEN);
    snprintf(effectiveAddr, MAX_LEN-1, "%x", func_addr);
    TRACE_EVENT_BEGIN(MINIGUI_TRACE_CATEGORY, effectiveAddr);
//    printf("enter %p\n", effectiveAddr);
#undef MAX_LEN
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_exit( void *func_addr, void *call_site )
{
    // instrument_print("Exit, call_site:%x\n func_addr:%x\n", call_site, func_addr);
#define MAX_LEN 17
    char effectiveAddr[MAX_LEN];
    memset(effectiveAddr, 0, MAX_LEN);
    snprintf(effectiveAddr, MAX_LEN-1, "%x", func_addr);
    TRACE_EVENT_END(MINIGUI_TRACE_CATEGORY);
//    printf("exit %p\n", effectiveAddr);
#undef MAX_LEN
}

#ifdef __cplusplus
}
#endif
