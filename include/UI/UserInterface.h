#ifndef PWR_AIZO_PROJECT1_USERINTERFACE_H
#define PWR_AIZO_PROJECT1_USERINTERFACE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Checkbox.h"
#include <iostream>

#define WINDOW_SIZE 800

class UserInterface {
public:
    explicit UserInterface();

private:
    sf::Font font;

    Checkbox checkbox = Checkbox();
    sf::RenderWindow window;
    void run();
};

#endif //PWR_AIZO_PROJECT1_USERINTERFACE_H
