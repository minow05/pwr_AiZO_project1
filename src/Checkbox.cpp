#include <iostream>
#include "../include/UI/Checkbox.h"

Checkbox::Checkbox(sf::Vector2f position) {
    box.setSize({20, 20});
    box.setPosition(position);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);
    box.setFillColor(sf::Color::Transparent);

    checkMark.setSize({20, 20});
//    checkMark.rotate(sf::degrees(45));
    checkMark.setPosition(position);
    checkMark.setFillColor(sf::Color::Green);

    checked = false;
}

void Checkbox::handleEvent(sf::RenderWindow &window) {
    sf::Vector2f mousePos(sf::Mouse::getPosition(window));
//    std::cout << isChecked() << std::endl;
    if (box.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        checked = !checked;
    }
}

void Checkbox::render(sf::RenderWindow &window) {
    window.draw(box);
    if (checked) {
        window.draw(checkMark);
    }
}


Checkbox::Checkbox() = default;
