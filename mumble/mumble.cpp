#include <limits>
#include <SFML/Audio.hpp>
#include "mumble.h"


#ifndef PI
#define PI 3.14159265358979323846f
#endif


Mumble::Mumble(const std::string &phrase) : Mumble(phrase, Voice()) {}

Mumble::Mumble(const std::string &phrase, const Voice &voice)
: phrase(phrase), position(0), voice(voice), rate(10000)
{
    // Generate the buffer data
    size = rate; // ONE SECOND :P
    data = new short[size];
    for (int i = 0; i < size; ++i)
    {
        float max = (float)std::numeric_limits<short>::max();
        float x = lerp(1.0f, 2.0f, (float)i/(float)size) * voice.averagePitch * (float)i / (float)size;
        data[i] = (short)(max * voice.baseWaveForm(x));
    }

    // Give the buffer to the sound
    buffer.loadFromSamples(data, size, 1, rate);
    sound.setBuffer(buffer);
}

Mumble::~Mumble()
{
    delete[] data;
}

void Mumble::play()
{
    sound.play();
}

void Mumble::stop()
{
    sound.stop();
}

float lerp(float a, float b, float x) {
    return a + x * (b - a);
}

float sin_one(float x) {
    return sinf(x * 2.0f * PI);
}

