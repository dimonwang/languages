#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#ifdef __cplusplus
extern "C" {
#endif
void  __attribute__ ((no_instrument_function)) enable_instrument(void);
void  __attribute__ ((no_instrument_function)) disable_instrument(void);
void  __attribute__((no_instrument_function, destructor)) main_destructor(void);
void  __attribute__((no_instrument_function)) __cyg_profile_func_enter(void *, void *);
void  __attribute__((no_instrument_function)) __cyg_profile_func_exit(void *, void *);
void initialize();
void deinitialize();
#ifdef __cplusplus
}
#endif
#define MINIGUI_TRACE_CATEGORY "minigui"
#endif
