#include <cmath>
#include <limits>
#include "SFML/Audio.hpp"

#ifndef PI
#define PI 3.14159265358979323846f
#endif


void curve_sin(float amplitude, float oscillations, short *data, int size) {
    float scale = oscillations * M_PI * 2.0f / static_cast<float>(size);
    for (int i = 0; i < size; ++i) {
        float x = i * scale;
        float val = (1.0f + sinf(i)) / std::numeric_limits<short>::max();
        data[i] = static_cast<short>(100.0f * val);
    }
}


int main(int argc, char **argv) {

    short wave[1024];
    curve_sin(100.0f, 100.0f, wave, 1024);

    return 0;
}
