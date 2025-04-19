#include <iostream>
#include <thread>
#include "../include/UI/Button.h"

Button::Button(sf::Vector2f position, float height, float width, sf::Font &font, const std::string& name) : font(font) {
    box.setPosition(position);
    box.setSize({height, width});
    text = sf::Text(font, name, 20);
    text.setPosition({position.x + 5, position.y + 5});
    text.setFillColor(sf::Color::Red);
}

void Button::handleEvent(sf::RenderWindow &window) {
    sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    if (box.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)) && !pressed) {
        pressed = true;
        pressClock.restart();
        box.setFillColor(sf::Color(120, 120, 120));
    }
}

void Button::update() {
    if (pressed) {
        if (pressClock.getElapsedTime().asMilliseconds() > 5) {
            pressed = false;
            box.setFillColor(sf::Color::White);
        } else if (pressClock.getElapsedTime().asSeconds() > 0.3f) {
        }
    }
}

void Button::render(sf::RenderWindow &window) {
    update();
    window.draw(box);
    window.draw(text);
}


