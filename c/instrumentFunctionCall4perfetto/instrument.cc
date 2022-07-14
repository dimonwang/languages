#include <stdio.h>
#include "instrument.h"
#include "perfetto.h"
#include <chrono>
#include <fstream>
#include <thread>

#define INSTRUMENT_FILE_PATH "instrument.log"
#define TRACE_FILE_PATH "example.pftrace"

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


std::unique_ptr<perfetto::TracingSession> StartTracing() {
  // The trace config defines which types of data sources are enabled for
  // recording. In this example we just need the "track_event" data source,
  // which corresponds to the TRACE_EVENT trace points.
  perfetto::TraceConfig cfg;
  cfg.add_buffers()->set_size_kb(1024000);
  auto* ds_cfg = cfg.add_data_sources()->mutable_config();
  ds_cfg->set_name("track_event");

  auto tracing_session = perfetto::Tracing::NewTrace();
  tracing_session->Setup(cfg);
  tracing_session->StartBlocking();
  return tracing_session;
}

void StopTracing(std::unique_ptr<perfetto::TracingSession> tracing_session) {
  // Make sure the last event is closed for this example.
  perfetto::TrackEvent::Flush();

  // Stop tracing and read the trace data.
  tracing_session->StopBlocking();
  std::vector<char> trace_data(tracing_session->ReadTraceBlocking());

  // Write the result into a file.
  // Note: To save memory with longer traces, you can tell Perfetto to write
  // directly into a file by passing a file descriptor into Setup() above.
  std::ofstream output;
  output.open(TRACE_FILE_PATH, std::ios::out | std::ios::binary);
  output.write(&trace_data[0], std::streamsize(trace_data.size()));
  output.close();
  PERFETTO_LOG(
      "Trace written in example.pftrace file. To read this trace in "
      "text form, run `./tools/traceconv text example.pftrace`");
}

#ifdef __cplusplus
extern "C" {
#endif

#define START_TRACING 0
#define STOP_TRACING  1
void dealTracing(int stop) {
    static std::unique_ptr<perfetto::TracingSession> tracing_session;
    if (stop)
        StopTracing(std::move(tracing_session));
    else
        tracing_session = StartTracing();
}

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
    dealTracing(0);
    perfetto::ProcessTrack process_track = perfetto::ProcessTrack::Current();
    perfetto::protos::gen::TrackDescriptor desc = process_track.Serialize();
    desc.mutable_process()->set_process_name("Example");
    perfetto::TrackEvent::SetTrackDescriptor(process_track, desc);
}

void deinitialize() {
    dealTracing(1);
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_enter( void *func_addr, void *call_site )
{
#define MAX_LEN 17
    if (_flag == 0) return;
    char virtualFuncAddr[MAX_LEN];
    memset(virtualFuncAddr, 0, MAX_LEN);
    snprintf(virtualFuncAddr, MAX_LEN-1, "%p", func_addr);

    char virtualCallerAddr[MAX_LEN];
    memset(virtualCallerAddr, 0, MAX_LEN);
    snprintf(virtualCallerAddr, MAX_LEN-1, "%p", call_site);

    TRACE_EVENT_BEGIN(MINIGUI_TRACE_CATEGORY, virtualFuncAddr);
    // printf("%s:%p, enter %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_enter,
            // virtualFuncAddr, virtualCallerAddr);
#undef MAX_LEN
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_exit( void *func_addr, void *call_site )
{
#define MAX_LEN 17
    if (_flag == 0) return;
    char virtualFuncAddr[MAX_LEN];
    memset(virtualFuncAddr, 0, MAX_LEN);
    snprintf(virtualFuncAddr, MAX_LEN-1, "%p", func_addr);

    char virtualCallerAddr[MAX_LEN];
    memset(virtualCallerAddr, 0, MAX_LEN);
    snprintf(virtualCallerAddr, MAX_LEN-1, "%p", call_site);
    TRACE_EVENT_END(MINIGUI_TRACE_CATEGORY);
    // printf("%s:%p, exit %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_exit, 
            // virtualFuncAddr, virtualCallerAddr);
#undef MAX_LEN
}

#ifdef __cplusplus
}
#endif
