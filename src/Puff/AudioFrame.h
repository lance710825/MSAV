﻿#ifndef PUFF_AUDIOFRAME_H
#define PUFF_AUDIOFRAME_H

#include "Frame.h"
#include "AudioFormat.h"

namespace Puff {

class AudioResample;
class AudioFramePrivate;
class PU_AV_EXPORT AudioFrame: public Frame
{
    DPTR_DECLARE_PRIVATE(AudioFrame)
public:
    AudioFrame(const AudioFormat &format = AudioFormat(), const ByteArray& data = ByteArray());
    virtual ~AudioFrame();

    bool isValid() const;

    int channelCount() const;

    int64_t duration();

    AudioFormat format() const;

    int samplePerChannel() const;
    void setSamplePerChannel(int channel);

    void setAudioResampler(AudioResample *resample);
    AudioFrame to(const AudioFormat &fmt) const;
};

}
#endif //PUFF_AUDIOFRAME_H
