#include "../include/UserInterface.h"
#include <SFML/Graphics.hpp>
#include <iostream>

UserInterface::UserInterface() {
    if (!this->font.openFromFile("../fonts/arial.ttf")) {
        std::cout << "Error loading font" << std::endl;
    }
    this -> window = sf::Window(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Sorting Algorithms");
}