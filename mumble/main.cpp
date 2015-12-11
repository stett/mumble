#include <SFML/System.hpp>
#include "mumble.h"

int main() {

    Mumble mumble("Phrase", Mumble::Voice());
    mumble.play();

    // Pause for a few seconds
    sf::Clock clock;
    while(clock.getElapsedTime().asSeconds() < 2.0f) {
        //std::cout << clock.getElapsedTime().asSeconds() << std::endl;
    }

    return 0;
}
