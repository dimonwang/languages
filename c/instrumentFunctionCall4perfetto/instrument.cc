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

static void initialize0() {
    perfetto::TracingInitArgs args;
    args.backends |= perfetto::kInProcessBackend;
    args.backends |= perfetto::kSystemBackend;

    perfetto::Tracing::Initialize(args);
    perfetto::TrackEvent::Register();
}


static std::unique_ptr<perfetto::TracingSession> StartTracing() {
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

static void StopTracing(std::unique_ptr<perfetto::TracingSession> tracing_session) {
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

// donnot delete this
void d123456789flg(){}
//////////////////////////////////////////
#define FUNCNAME_MAX_LEN (256)
typedef struct _ITEM {
    long long effectiveAddr;
    char funcName[FUNCNAME_MAX_LEN];
} ITEM;

static std::vector<ITEM> symbols;
static bool initSymbols() {
    FILE *p = fopen("./symbols.txt", "r");
    if (p == NULL) {
        printf("open file error:%s\n", strerror(errno));
        return false;
    }

#define LINE_LEN 1024
    bool finished = false;
    while (!finished) {
        char cnt[LINE_LEN];
        memset(cnt, 0, LINE_LEN);
        if (fgets(cnt, LINE_LEN, p) == NULL) {
            printf("finished\n");
            break;
        }

        if (strlen(cnt) <= 16) {
            printf("empty line?\n");
            continue;
        }

        if (cnt[strlen(cnt)-1] == '\n') {
            cnt[strlen(cnt)-1] = '\0';
        }

        char *sep = strstr(cnt, " ");
        ITEM item;
        strncpy(item.funcName, sep+1, FUNCNAME_MAX_LEN);
        *sep = '\0';
        item.effectiveAddr = strtoll(cnt, NULL, 16);
        symbols.push_back(item);
        // printf("add item, effectaddr:%016llx, funcName:%s\n", item.effectiveAddr, item.funcName);
    }
#undef LINE_LEN

    fclose(p);
    return true;
}

static void dumpSymbols() {
    if (symbols.empty()) {
        initSymbols();
    }

    int idx = 1;
    for (auto iter:symbols) {
        printf("idx:%d, addr:%016llx, name:%s\n", idx++, iter.effectiveAddr, iter.funcName);
    }
}

static long long offset = 0;
static int initOffset()
{
    printf("%s\n", __FUNCTION__);
    FILE *p = fopen("./symbol_flag.txt", "r");
    if (p == NULL) {
        printf("open file error:%s\n", strerror(errno));
        return 1;
    }

#define MAX_LEN 17
    char buf[MAX_LEN];
    memset(buf, 0, MAX_LEN);
    if (fgets(buf, MAX_LEN, p) == NULL) {
        printf("fgets error\n");
        fclose(p);
        return 2;
    }
    long long ea = strtoll(buf, NULL, 16);
    offset = (long long)d123456789flg - ea;
    printf("EA:%016llx, flag:%016llx, offset:%016llx\n", ea, (long long)d123456789flg, offset);
    fclose(p);
#undef MAX_LEN
    return 0;
}

static long long getOffset() {
    if (offset == 0) {
        initOffset();
    }

    return offset;
}

#define MIN(a,b) ((a > b)?b:a)
static int getFunctionNameByEA(const long long effectiveAddr, char* fname, const int fname_len) {
    if (fname == NULL) {
        printf("fname is null\n");
        return 1;
    }
    if (symbols.empty()) {
        initSymbols();
    }

    for(auto iter:symbols) {
        if (iter.effectiveAddr == effectiveAddr) {
            strncpy(fname, iter.funcName, MIN(fname_len, FUNCNAME_MAX_LEN));
            return 0;
        }
    }

    //not found
    return 2;
}

static int getFunctionNameByVA(const long long va, char* fname, const int fname_len) {
    if (fname == NULL) {
        printf("fname is null\n");
        return 10;
    }

    return getFunctionNameByEA(va-getOffset(), fname, fname_len);

}

void  __attribute__((no_instrument_function)) __cyg_profile_func_enter( void *func_addr, void *call_site )
{
#define MAX_ADDR_LEN 128
    if (_flag == 0) return;
    char virtualFunc[MAX_ADDR_LEN];
    memset(virtualFunc, 0, MAX_ADDR_LEN);
    if (getFunctionNameByVA((long long)func_addr, virtualFunc, MAX_ADDR_LEN) != 0) {
        snprintf(virtualFunc, MAX_ADDR_LEN-1, "%p", func_addr);
        printf("not find func:%s\n", virtualFunc);
    }

    TRACE_EVENT_BEGIN(MINIGUI_TRACE_CATEGORY, virtualFunc);
    char virtualCaller[MAX_ADDR_LEN];
    memset(virtualCaller, 0, MAX_ADDR_LEN);
    if (getFunctionNameByVA((long long)func_addr, virtualCaller, MAX_ADDR_LEN) != 0) {
        snprintf(virtualCaller, MAX_ADDR_LEN-1, "%p", call_site);
        printf("not find func:%s\n", virtualFunc);
    }

    // printf("%s:%p, enter %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_enter,
            // virtualFunc, virtualCaller);
#undef MAX_ADDR_LEN
}

void  __attribute__((no_instrument_function)) __cyg_profile_func_exit( void *func_addr, void *call_site )
{
#define MAX_ADDR_LEN 128
    if (_flag == 0) return;
    TRACE_EVENT_END(MINIGUI_TRACE_CATEGORY);
    char virtualFunc[MAX_ADDR_LEN];
    memset(virtualFunc, 0, MAX_ADDR_LEN);
    if (getFunctionNameByVA((long long)func_addr, virtualFunc, MAX_ADDR_LEN) != 0) {
        snprintf(virtualFunc, MAX_ADDR_LEN-1, "%p", func_addr);
        printf("not find func:%s\n", virtualFunc);
    }

    char virtualCaller[MAX_ADDR_LEN];
    memset(virtualCaller, 0, MAX_ADDR_LEN);
    if (getFunctionNameByVA((long long)func_addr, virtualCaller, MAX_ADDR_LEN) != 0) {
        snprintf(virtualCaller, MAX_ADDR_LEN-1, "%p", call_site);
        printf("not find func:%s\n", virtualFunc);
    }
    // printf("%s:%p, exit %s, caller %s\n", __FUNCTION__, (void*) __cyg_profile_func_exit, 
            // virtualFunc, virtualCaller);
#undef MAX_ADDR_LEN
}

#ifdef __cplusplus
}
#endif
