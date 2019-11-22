#include <iostream>
#include <string>
#include <algorithm>

#include "Trapeze.h"
#include "Queue.h"

int main() {
    std::string command;
    Containers::Queue<Trapeze<int>> figures;
    while (std::cin >> command) {
        if (command == "add") {
            Trapeze<int> new_figure;
            try {
                std::cin >> new_figure;
            } catch (std::exception& ex) {
                std::cout << ex.what() << "\n";
            }
            figures.Push(new_figure);
        } else if (command == "erase") {
            size_t index;
            std::cin >> index;
            try {
                auto it = std::next(figures.begin(), index);
                figures.Erase(it);
            } catch (...) {
                std::cout << "Index is too big\n";
                continue;
            }
        } else if (command == "print") {
            std::for_each(figures.begin(), figures.end(), [] (const Trapeze<int>& fig) {
                std::cout << fig << " ";
            });
            std::cout << "\n";
        } else if (command == "count") {
            size_t required_area;
            std::cin >> required_area;
            std::cout << std::count_if(figures.begin(), figures.end(), [&required_area] (const Trapeze<int>& fig) {
                return fig.Area() < required_area;
            });
            std::cout << "\n";
        } else {
            std::cout << "Incorrect command" << "\n";
            std::cin.ignore(32767, '\n');
        }
    }
}