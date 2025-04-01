#include "UI/UserInterface.h"

#define offset 18



UserInterface::UserInterface() {
    if(!font.openFromFile("../fonts/Arial.ttf")){
        std::cout << "Error loading font\n";
    }
    window = sf::RenderWindow(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Menu");
    window.setFramerateLimit(60);

    checkbox = Checkbox(sf::Vector2f(WINDOW_SIZE/4.0f, WINDOW_SIZE/4.0f));
    checkBoxLabel.setPosition({WINDOW_SIZE/4.0f - offset , WINDOW_SIZE/4.0f - 20});
    checkBoxLabel.setFillColor(sf::Color::White);

    sizeBar = SlideBar(sf::Vector2f(WINDOW_SIZE/2.0f, WINDOW_SIZE/4.0f), WINDOW_SIZE/3.0f, 1000, 10000);
    sizeBarLabel.setPosition({WINDOW_SIZE/2.0f, WINDOW_SIZE/4.0f - 30});
    sizeBarLabel.setFillColor(sf::Color::White);

    sizeBarValue.setPosition({WINDOW_SIZE/2.0f + WINDOW_SIZE/6.0f, WINDOW_SIZE/4.0f - 30});
    sizeBarValue.setFillColor(sf::Color::White);

    std::vector<Checkbox> checkboxes;
    std::vector<sf::Text> checkboxLabels;



    checkboxGroup = CheckboxGroup(checkboxes, checkboxLabels);

    window.clear(sf::Color::Black);
    run();
}

void UserInterface::run(){
    while(window.isOpen()) {
        window.handleEvents(
                [this](const sf::Event::Closed&) {
                    window.close();
                },

                [this](const sf::Event::MouseButtonPressed& mouseEvent) {
                    if (mouseEvent.button == sf::Mouse::Button::Left) {
                        checkbox.handleEvent(window);
                        sizeBar.handleEvent(window);
                    }
                },
                [this](const sf::Event::MouseMoved& mouseEvent) {
                    if (mouseEvent.position.x > 0 && mouseEvent.position.x < WINDOW_SIZE && mouseEvent.position.y > 0 && mouseEvent.position.y < WINDOW_SIZE) {
                        sizeBar.handleEvent(window);
                    }
                }
        );

        window.clear(sf::Color::Black);

        sizeBarValue.setString(std::to_string(sizeBar.getValue()));

        checkbox.render(window);
        sizeBar.render(window);
        window.draw(checkBoxLabel);
        window.draw(sizeBarLabel);
        window.draw(sizeBarValue);
        window.display();
    }
}