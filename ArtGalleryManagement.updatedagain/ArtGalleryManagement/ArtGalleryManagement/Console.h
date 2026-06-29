#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

// Small console helper utilities: robust input and lightweight ANSI styling.
namespace Console {
    // ANSI colour codes (no-op on terminals that don't support them).
    extern const std::string RESET;
    extern const std::string BOLD;
    extern const std::string CYAN;
    extern const std::string GREEN;
    extern const std::string YELLOW;
    extern const std::string RED;
    extern const std::string DIM;

    // Read an integer, re-prompting until valid input is given. Never loops
    // forever on bad (non-numeric) input the way `cin >> int` does.
    int readInt(const std::string& prompt);

    // Read a full line of text.
    std::string readLine(const std::string& prompt);

    // Formatted output helpers.
    void title(const std::string& text);   // Boxed/coloured heading
    void separator();                       // Horizontal rule
    void success(const std::string& text);  // Green message
    void error(const std::string& text);    // Red message
    void info(const std::string& text);     // Cyan message
}

#endif /* CONSOLE_H */
