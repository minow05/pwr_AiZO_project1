//
// Created by minow on 13-Mar-25.
//
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <thread>
#include <atomic>
#include <functional>

#ifndef PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define WINDOW_SIZE 800
#define WINDOW_SIZE_FLOAT 800.0

template<class Derived>
class SortingAlgorithm {
public:

    explicit SortingAlgorithm(bool slow){
        setMode(slow);
        this -> slowMode = slow;
    }
    virtual ~SortingAlgorithm() = default;

    void setMode(bool slow){
        delayFunction = slow ? std::bind(&SortingAlgorithm::delayReal, this) : std::bind(&SortingAlgorithm::delayNone, this);
        this -> slowMode = slow;
    }

    template<typename T>
    void sort(T *arr, int size) {
        if (slowMode){
            renderThread = std::thread(&SortingAlgorithm::drawPlot<T>, this, arr, size);
        }
        auto start = std::chrono::high_resolution_clock::now();
        static_cast<Derived*>(this)->sortImpl(arr, size);
        auto stop = std::chrono::high_resolution_clock::now();
        this -> duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        this -> printTime(size);
        if (renderThread.joinable()) renderThread.detach();

    }
    //Curiously recurring template pattern (CRTP) because we want to inherit virtual template method

    template<typename T>
    void printArray(T *arr, int size){
        printf("Array: \n");
        for (int i = 0; i < size; ++i){
            std::cout << *(arr + i) << " ";
        }
        std::cout << std::endl;
    };

    template<typename T>
    void drawPlot(T *arr, int size){
        sf::RenderWindow window{sf::VideoMode({WINDOW_SIZE, WINDOW_SIZE}), "Sorting Algorithm"};
        T max = *std::max_element(arr, arr + size);
        float max_float = static_cast<float>(max);
        float size_float = static_cast<float>(size);
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }
            window.clear(sf::Color::Black);
            updatePlot(arr, size, size_float, window, max_float);
            window.display();
            std::this_thread::sleep_for(std::chrono::milliseconds(16));
        }
    }


    template<typename T>
    void updatePlot (T *arr, int size, float size_float, sf::RenderWindow &window, float &max){

        for (int i = 0; i < size; i++){
            float height = static_cast<float>(arr[i]) / max * WINDOW_SIZE_FLOAT;
            float width = WINDOW_SIZE_FLOAT/size_float; //floor z size'a
            sf::RectangleShape rectangle(sf::Vector2f(width, height));
            rectangle.setPosition(sf::Vector2f(static_cast<float>(i) * width, WINDOW_SIZE_FLOAT - height));
            rectangle.setFillColor(sf::Color(2, 48, 32));
            window.draw(rectangle);
        }
    }

    void printTime(int size){
        std::cout << "Time: " << static_cast<float>(duration.count())/static_cast<float>(size) << " milliseconds" << std::endl;
    }

protected:
    std::chrono::microseconds duration{};
    bool slowMode;
    std::thread renderThread;
    template<typename T>
    void sortImpl(T *arr, int size){
        if (size <= 1) return;
        std::sort(arr, arr + size);
    };
    std::function<void()> delayFunction;
    void delayReal() const {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    void delayNone() const {}
};



#endif //PWR_AIZO_PROJECT1_SORTINGALGORITHM_H