#include "../include/UI/Dropdown.h"
#include "../include/Algorithms/Heap.h"
#include "../include/Algorithms/Quick.h"
#include "../include/Algorithms/Insertion.h"
#include "../include/Algorithms/Shell.h"
#include "../include/DataGeneration.h"

Dropdown::Dropdown(sf::Vector2f position, float width, float height, const std::vector<std::string> &items, sf::Font &font) : font(font)  {
    box.setPosition(position);
    box.setSize({ width, height });
    box.setFillColor(sf::Color(200, 200, 200));
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2);

    selectedText = sf::Text(font, items[0], 20);
    selectedText.setFillColor(sf::Color::Black);
    selectedText.setPosition({position.x + 5, position.y + 5});

    float optionY = position.y + height;
    for (const auto& item : items) {
        sf::RectangleShape optBox;
        optBox.setPosition({position.x, optionY});
        optBox.setSize({ width, height });
        optBox.setFillColor(sf::Color(230, 230, 230));
        optBox.setOutlineColor(sf::Color::Black);
        optBox.setOutlineThickness(1);
        optionBoxes.push_back(optBox);

        sf::Text optText(font, item, 20);
        optText.setFillColor(sf::Color::Black);
        optText.setPosition({position.x + 5, optionY + 5});
        options.push_back(optText);

        optionY += height;
    }
}

void Dropdown::handleEvent(sf::RenderWindow &window) {
    sf::Vector2f mousePos(sf::Mouse::getPosition(window));
    if (box.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        expanded = !expanded;
    } else if (expanded) {
        for (size_t i = 0; i < optionBoxes.size(); ++i) {
            if (optionBoxes[i].getGlobalBounds().contains(mousePos)) {
                selectedIndex = i;
                selectedText.setString(options[i].getString());
                expanded = false;
                break;
            }
        }
    } else {
        expanded = false;
    }
}

void Dropdown::render(sf::RenderWindow &window) {
    window.draw(box);
    window.draw(selectedText);
    if (expanded) {
        for (size_t i = 0; i < options.size(); ++i) {
            window.draw(optionBoxes[i]);
            window.draw(options[i]);
        }
    }
}

std::string Dropdown::getSelected() const {
    return options[selectedIndex].getString();
}