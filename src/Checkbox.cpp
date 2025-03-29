#include "../include/UI/Checkbox.h"

Checkbox::Checkbox(sf::Vector2f position) {
    box.setSize({20, 20});
    box.setPosition(position);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);
    box.setFillColor(sf::Color::Transparent);

    checkMark.setSize({15, 2});
    checkMark.rotate(sf::degrees(45));
    checkMark.setPosition(position);
    checkMark.setFillColor(sf::Color::Green);
}

void Checkbox::handleEvent(sf::Event event) {
    sf::Vector2f mousePos(sf::Mouse::getPosition());
    if (box.getGlobalBounds().contains(mousePos)) {
        checked = !checked;
    }
}

void Checkbox::render(sf::RenderWindow &window) {
    window.draw(box);
    if (checked) {
        window.draw(checkMark);
    }
}

bool Checkbox::isChecked() {
    return checked;
}

Checkbox::Checkbox(){}
