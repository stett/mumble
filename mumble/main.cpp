#include <cmath>
#include <limits>
#include <iostream>
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#define SAMPLE_RATE 10000 // samples/seconds


void curve_sin(float amplitude, float oscillations, short *data, int size) {
    float scale = oscillations * PI * 2.0f / static_cast<float>(size);
    for (int i = 0; i < size; ++i) {
        float x = i * scale;
        float val = amplitude * sinf(x);
        data[i] = static_cast<short>(100.0f * val);
    }
}


int main() {

    short wave[10000];
    curve_sin(2000.0f, 100.0f, wave, 10000);

    // Load the wave into a buffer
    sf::SoundBuffer buffer;
    if (!buffer.loadFromSamples(wave, 1024, 1, SAMPLE_RATE))
        return -1;

    unsigned int rate = buffer.getSampleRate();

    const short *samples = buffer.getSamples();
    for (int i = 0; i < buffer.getSampleCount(); ++i)
        std::cout << i << ": " << samples[i] << std::endl;

    // Wrap 'dat buffer in a sound object
    sf::Sound sound(buffer);
    sound.play();

    // Pause for a few seconds
    sf::Clock clock;
    while(clock.getElapsedTime().asSeconds() < 2.0f) {
        //std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    }

    return 0;
}
