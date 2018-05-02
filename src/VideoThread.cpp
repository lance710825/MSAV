#include "VideoThread.h"
#include "AVThread_p.h"
#include "VideoDecoder.h"

namespace Puff {

class VideoThreadPrivate: public AVThreadPrivate
{
public:
    VideoThreadPrivate() {}
    ~VideoThreadPrivate() {}
};

VideoThread::VideoThread()//: AVThread()
{

}

VideoThread::~VideoThread()
{

}

void VideoThread::run()
{
    DPTR_D(VideoThread);

    auto *dec = dynamic_cast<VideoDecoder *>(d.decoder);

    Packet pkt;
    VideoFrame frame;

    while (!d.stopped) {

        if (!pkt.isValid()) {
            pkt = d.packets.dequeue();
        }

        if (!dec->decode(pkt)) {
            continue;
        }
        frame = dec->frame();
    }

    AVThread::run();
}

}
