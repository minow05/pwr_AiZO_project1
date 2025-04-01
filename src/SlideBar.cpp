#include <iostream>
#include <algorithm>
#include "../include/UI/SlideBar.h"

#define height 5.f
#define radius 15.f

SlideBar::SlideBar() {}

SlideBar::SlideBar(sf::Vector2f position, float width, int minValue, int maxValue) : maxValue(maxValue), minValue(minValue){
    bar = sf::RectangleShape(sf::Vector2f(width, height));
    bar.setPosition(position);
    bar.setFillColor(sf::Color::White);
    knob = sf::CircleShape(radius);
    knob.setFillColor(sf::Color::Red);
    knob.setPosition({position.x, position.y - radius + height/2.f});
}
void SlideBar::handleEvent(sf::RenderWindow &window) {
//    std::cout << currentValue << std::endl;
    sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    if (knob.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            float newX = std::clamp(static_cast<float>(mousePos.x), bar.getPosition().x, bar.getPosition().x + bar.getSize().x);

            knob.setPosition({newX - radius, knob.getPosition().y});

            float percent = (newX - bar.getPosition().x) / bar.getSize().x;
            currentValue = maxValue - percent * (maxValue - minValue);
        }
    }
}

void SlideBar::render(sf::RenderWindow &window) {
    window.draw(bar);
    window.draw(knob);
}

int SlideBar::getValue() const {
    return currentValue;
}


