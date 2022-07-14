#include <stdio.h>
/* #include "instrument.h" */
#include "perfetto.h"
#include <unistd.h>

#define MINIGUI_TRACE_CATEGORY "minigui_no_inst"

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

int mul(int i, int j) {
    return i*j;
}

int addmul(int i, int j) {

    TRACE_EVENT_BEGIN(MINIGUI_TRACE_CATEGORY, "dimon");
    int k1,k2;
    k1 = i+j;
    /* enable_instrument(); */
    k2=mul(i,j);
    /* disable_instrument(); */
    sleep(1);
    TRACE_EVENT_END(MINIGUI_TRACE_CATEGORY);
    return k1+k2;
}

void d123456789flg(){}

int main(void) {
    initialize0();
    printf("main:  %x\n", main);
    printf("addmul:%x\n", addmul);
    printf("mul:   %x\n", mul);
    /* enable_instrument(); */
    int round = 0;
    while(round++ < 50000000000) {
        int result = addmul(3,5);
        printf("round:%d, result:%d\n", round, result);
        /* sleep(1); */
    }
    /* disable_instrument(); */

    return 0;
}
