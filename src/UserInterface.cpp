#include "UI/UserInterface.h"

#define offset 18



UserInterface::UserInterface() {
    if(!font.openFromFile(R"(C:\GitHub_repos\pwr_AiZO_project1\fonts\Arial.ttf)")){
        std::cout << "Error loading font\n";
    }
    window = sf::RenderWindow(sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Menu");
    window.setFramerateLimit(60);

    checkbox = Checkbox(sf::Vector2f(WINDOW_SIZE/4.0f, WINDOW_SIZE/4.0f));
    checkBoxLabel.setPosition({WINDOW_SIZE/4.0f - offset , WINDOW_SIZE/4.0f - 20});
    checkBoxLabel.setFillColor(sf::Color::White);

    sizeBar = SlideBar(sf::Vector2f(WINDOW_SIZE/2.0f, WINDOW_SIZE/4.0f), WINDOW_SIZE/3.0f, 500, 1000000);
    sizeBarLabel.setPosition({WINDOW_SIZE/2.0f, WINDOW_SIZE/4.0f - 30});
    sizeBarLabel.setFillColor(sf::Color::White);

    sizeBarValue.setPosition({WINDOW_SIZE/2.0f + WINDOW_SIZE/5.0f, WINDOW_SIZE/4.0f - 30});
    sizeBarValue.setFillColor(sf::Color::White);

    std::vector<std::string> algorithmsDropdownItems = {"Insertion Sort", "Quick Sort", "Heap Sort", "Shell Sort"};
    algorithmsDropdown = Dropdown(sf::Vector2f(WINDOW_SIZE_FLOAT/10.f, WINDOW_SIZE_FLOAT * 2.0f / 3.0f), 150, 40, algorithmsDropdownItems, font);

    std::vector<std::string> datatypeDropdownItems = {"integer", "floating point"};
    datatypeDropdown = Dropdown(sf::Vector2f(WINDOW_SIZE_FLOAT * 3.f/10.f, WINDOW_SIZE_FLOAT * 2.0f / 3.0f), 150, 40, datatypeDropdownItems, font);

    std::vector<std::string> dataFormat = {"Random", "Sorted", "Reverse Sorted"};
    dataFormatDropdown = Dropdown(sf::Vector2f(WINDOW_SIZE_FLOAT * 5.0f / 10.0f, WINDOW_SIZE_FLOAT * 2.0f / 3.0f), 150, 40, dataFormat, font);

    runButton = Button(sf::Vector2f(WINDOW_SIZE_FLOAT * 4.0f / 5.0f, WINDOW_SIZE_FLOAT * 2.0f / 3.0f), 50, 40, font, "Run");

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
                        runButton.handleEvent(window);
                        checkbox.handleEvent(window);
                        sizeBar.handleEvent(window);
                        algorithmsDropdown.handleEvent(window);
                        datatypeDropdown.handleEvent(window);
                        dataFormatDropdown.handleEvent(window);
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
        algorithmsDropdown.render(window);
        datatypeDropdown.render(window);
        dataFormatDropdown.render(window);
        runButton.render(window);
        window.draw(checkBoxLabel);
        window.draw(sizeBarLabel);
        window.draw(sizeBarValue);
        window.display();

        if (runButton.pressed){
            std::variant<Quick, Insertion, Heap, Shell> algorithm(std::in_place_type<Insertion>, false);
            std::variant<int, float> datatype;
            std::string dataFormat;
            auto selectedString = algorithmsDropdown.getSelected();
            auto selectedDatatype = datatypeDropdown.getSelected();
            auto selectedDataFormat = dataFormatDropdown.getSelected();
            if (selectedString == "Insertion Sort"){
                algorithm.emplace<Insertion>(false);
            } else if (selectedString == "Quick Sort"){
                algorithm.emplace<Quick>(false);
            } else if (selectedString == "Heap Sort"){
                algorithm.emplace<Heap>(false);
            } else if (selectedString == "Shell Sort"){
                algorithm.emplace<Shell>(false);
            }
            if (checkbox.checked) {
                std::visit([](auto& alg) -> void {
                   alg.setMode(true);
                }, algorithm);
            }
            if (selectedDatatype == "integer"){
                datatype.emplace<int>();
            } else if (selectedDatatype == "floating point"){
                datatype.emplace<float>();
            }
            if (selectedDataFormat == "Random"){
                dataFormat = "random";
            } else if (selectedDataFormat == "Sorted"){
                dataFormat = "sorted";
            } else if (selectedDataFormat == "Reverse Sorted"){
                dataFormat = "reverseSorted";
            }
            std::visit([this, &dataFormat](auto& type, auto& alg) {
                using T = std::decay_t<decltype(type)>;
                DataGeneration<T> dataGeneration(sizeBar.getValue());
                T* data = dataGeneration.getArray(dataFormat);
                alg.sort(data, sizeBar.getValue());
            }, datatype, algorithm);
        }
    }
}