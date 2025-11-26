#include <iostream>
#include <string>
#include <memory>
#include "include/array.hpp"
#include "include/triangle.hpp"
#include "include/rectangle.hpp"
#include "include/square.hpp"


int main() {
    Array arr;
    size_t N;
    if (!(std::cin >> N)) {
        std::cerr << "Invalid input\n";
        return 1;
    }

    for (size_t i = 0; i < N; ++i) {
        char t;
        std::cin >> t;
        Figure* f = nullptr;
        if (t == 'T' || t == 't') {
            f = new Triangle();
        } else if (t == 'R' || t == 'r') {
            f = new Rectangle();
        } else if (t == 'S' || t == 's') {
            f = new Square();
        } else {
            std::cerr << "Unknown figure type: " << t << "\n";
            --i;
            continue;
        }
        std::cin >> *f;
        if (!f->isCorrect()) {
            std::cerr << "Figure " << f->getName() << " is incorrect. Skipping.\n";
            delete f;
        } else {
            arr.push_back(f);
        }
    }

    arr.printAll();
    std::cout << "\nTotal area = " << arr.totalArea() << "\n";
    std::cout << "\nIf you want to delete a figure by index, enter index (-1 to skip): ";
    int idx;
    if (std::cin >> idx) {
        if (idx >= 0) {
            try {
                arr.remove(static_cast<size_t>(idx));
                std::cout << "After deletion:\n";
                arr.printAll();
                std::cout << "Total area = " << arr.totalArea() << "\n";
            } catch (const std::exception& e) {
                std::cerr << "Error removing: " << e.what() << "\n";
            }
        }
    }
    return 0;
}
