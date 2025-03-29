#ifndef PWR_AIZO_PROJECT1_CHECKBOX_H
#define PWR_AIZO_PROJECT1_CHECKBOX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Checkbox{
public:
    Checkbox();
    explicit Checkbox(sf::Vector2f position);

    void handleEvent(sf::Event event);
    void render(sf::RenderWindow& window);
    bool isChecked();
private:
    sf::RectangleShape box;
    sf::RectangleShape checkMark;
    bool checked;
};

#endif //PWR_AIZO_PROJECT1_CHECKBOX_H
