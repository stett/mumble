#pragma once

#include <string>
#include <limits>
#include <cmath>
#include <SFML/Audio.hpp>


float lerp(float a, float b, float x);
float sin_one(float x);


class Mumble
{
    // Types
public:
    struct Voice
    {
        float vowelsPerSecond;          ///< Vowels per second.
        float averagePitch;             ///< In hertz (human voice ranges from 85-180).
        float(*baseWaveForm)(float);    ///< Function pointer to the basic waveform function, with period 1 and range [-1,1].
        Voice() : vowelsPerSecond(5.0f), averagePitch(130.0f), baseWaveForm(sin_one) {}
    };

    // Members
private:
    std::string phrase;
    int position;
    Voice voice;
    unsigned int rate;
    short *data;
    unsigned int size;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    // 'Tors
public:
    Mumble(const std::string &phrase);
    Mumble(const std::string &phrase, const Voice &voice);
    Mumble(const Mumble &) = delete;
    ~Mumble();

    // Public methods
public:
    void play();
    void stop();

    // Operators
public:
    Mumble &operator=(const Mumble &) = delete;
};


/*void wave_sin(short *buffer, unsigned int size, float frequencyRange[2], float amplitudeRange[2], unsigned int rate)
{

}*/
