#include "native_publish.h"
#include "h264_publish.h"

VideoPublisher *videoPublisher = NULL;

/**
 * 编码开始
 * @param url
 * @param width
 * @param height
 */
int startPublish(char *url,int width, int height) {
    if (videoPublisher == NULL) {
        videoPublisher = new H264Publisher();
    }
    videoPublisher->InitPublish(url, width, height);
    return videoPublisher->StartPublish();
}

/**
 * 编码结束
 */
void stopPublish() {
    if (NULL != videoPublisher) {
        videoPublisher->StopPublish();
        videoPublisher = NULL;
    }
}

/**
 * 处理相机回调的预览数据
 * @param data
 * @param width
 * @param height
 */
int processFrame(char *data, int width, int height) {
    if (NULL != videoPublisher && videoPublisher->isTransform()) {
        return videoPublisher->EncodeBuffer((unsigned char *) data);
    }
    return -1;
}
