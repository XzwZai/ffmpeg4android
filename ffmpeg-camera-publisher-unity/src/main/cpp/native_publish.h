#ifndef NATIVE_PUBLISH
#define NATIVE_PUBLISH
#ifdef __cplusplus
extern "C" {
#endif

#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>

    int startPublish(char *url, int width, int height);

    void stopPublish();

    int processFrame(char *data, int width, int height);

#ifdef __cplusplus
}
#endif
#endif
