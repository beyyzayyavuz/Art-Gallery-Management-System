#include "Console.h"
#include <iostream>
#include <limits>
#include <sstream>

namespace Console {
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string CYAN = "\033[36m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string RED = "\033[31m";
    const std::string DIM = "\033[2m";

    int readInt(const std::string& prompt) {
        while (true) {
            std::cout << prompt;
            std::string line;
            if (!std::getline(std::cin, line)) {
                // End of input: return a sentinel so callers can exit cleanly.
                return -1;
            }
            std::istringstream iss(line);
            int value;
            char leftover;
            if ((iss >> value) && !(iss >> leftover)) {
                return value;
            }
            error("Please enter a valid number.");
        }
    }

    std::string readLine(const std::string& prompt) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    void title(const std::string& text) {
        std::cout << BOLD << CYAN << "\n=== " << text << " ===" << RESET << "\n";
    }

    void separator() {
        std::cout << DIM << "------------------------------------------" << RESET << "\n";
    }

    void success(const std::string& text) {
        std::cout << GREEN << text << RESET << "\n";
    }

    void error(const std::string& text) {
        std::cout << RED << text << RESET << "\n";
    }

    void info(const std::string& text) {
        std::cout << CYAN << text << RESET << "\n";
    }
}
