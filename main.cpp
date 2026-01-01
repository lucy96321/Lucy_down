#include <iostream>
#include <limits>
#include <cmath>

double getNumber(const char* prompt) {
    double x;
    while (true) {
        std::cout << prompt;
        if (std::cin >> x) return x;
        std::cout << "Invalid input. Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int getChoice() {
    int c;
    while (true) {
        std::cout << "\nChoose operation:\n"
                  << " 1) Add (+)\n"
                  << " 2) Subtract (-)\n"
                  << " 3) Multiply (*)\n"
                  << " 4) Divide (/)\n"
                  << " 5) Power (x^y)\n"
                  << " 6) Modulo (%)\n"
                  << " 7) Square root (√x)\n"
                  << " 0) Exit\n"
                  << "Your choice: ";
        if (std::cin >> c && c >= 0 && c <= 7) return c;
        std::cout << "Invalid choice. Try again.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    std::cout << "Simple C++ Calculator\n";
    while (true) {
        int choice = getChoice();
        if (choice == 0) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice == 7) {
            double x = getNumber("Enter x: ");
            if (x < 0) {
                std::cout << "Error: sqrt of negative number is not real.\n";
            } else {
                std::cout << "Result: " << std::sqrt(x) << "\n";
            }
            continue;
        }

        // Binary operations
        double a = getNumber("Enter a: ");
        double b = getNumber("Enter b: ");

        switch (choice) {
            case 1:
                std::cout << "Result: " << (a + b) << "\n";
                break;
            case 2:
                std::cout << "Result: " << (a - b) << "\n";
                break;
            case 3:
                std::cout << "Result: " << (a * b) << "\n";
                break;
            case 4:
                if (b == 0) std::cout << "Error: division by zero.\n";
                else std::cout << "Result: " << (a / b) << "\n";
                break;
            case 5:
                std::cout << "Result: " << std::pow(a, b) << "\n";
                break;
            case 6: {
                // Modulo for integers
                long long ai = static_cast<long long>(a);
                long long bi = static_cast<long long>(b);
                if (bi == 0) std::cout << "Error: modulo by zero.\n";
                else std::cout << "Result: " << (ai % bi)
                               << " (using integer modulo)\n";
                break;
            }
            default:
                std::cout << "Unknown operation.\n";
        }
    }
    return 0;
}
