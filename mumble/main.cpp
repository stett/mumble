#include <cmath>
#include <limits>
#include "SFML/Audio.hpp"

#ifndef PI
#define PI 3.14159265358979323846f
#endif


void curve_sin(float amplitude, float oscillations, short *data, int size) {
    float scale = oscillations * PI * 2.0f / static_cast<float>(size);
    for (int i = 0; i < size; ++i) {
        float x = i * scale;
        float val = amplitude * (1.0f + sinf(x)) / std::numeric_limits<short>::max();
        data[i] = static_cast<short>(100.0f * val);
    }
}


int main() {

    short wave[1024];
    curve_sin(100.0f, 100.0f, wave, 1024);
    sf::SoundBuffer buffer;
    buffer.loadFromSamples(wave, 1024, 1, 512);

    return 0;
}
