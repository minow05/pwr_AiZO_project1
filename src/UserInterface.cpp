#include "UI/UserInterface.h"

UserInterface::UserInterface() {
    if(!font.openFromFile("../fonts/JetBrainsMono-Regular.ttf")){
        std::cout << "Error loading font\n";
    }
    checkbox = Checkbox(sf::Vector2f(200, 200));

    window = sf::RenderWindow(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Menu");
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
                        checkbox.handleEvent(mouseEvent);
                    }
                }


        );
    }
}
