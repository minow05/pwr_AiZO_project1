

#ifndef PWR_AIZO_PROJECT1_USERINTERFACE_H
#define PWR_AIZO_PROJECT1_USERINTERFACE_H

#include <SFML/Graphics.hpp>

#define WINDOW_SIZE 800

class UserInterface {
public:
    UserInterface();
private:
    sf::Window window;

    sf::Font font;
    std::array<std::string, 4> algorithms;
};

#endif //PWR_AIZO_PROJECT1_USERINTERFACE_H
