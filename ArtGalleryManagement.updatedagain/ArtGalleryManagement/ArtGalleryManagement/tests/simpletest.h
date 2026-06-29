#ifndef SIMPLETEST_H
#define SIMPLETEST_H

// A tiny, dependency-free test harness. Enough to demonstrate unit testing
// in CI without pulling in an external framework.
#include <iostream>

namespace simpletest {
    inline int& failures() { static int f = 0; return f; }
    inline int& checks() { static int c = 0; return c; }
}

#define CHECK(cond)                                                            \
    do {                                                                       \
        ++simpletest::checks();                                                \
        if (!(cond)) {                                                         \
            ++simpletest::failures();                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__                \
                      << "  " << #cond << "\n";                                \
        }                                                                      \
    } while (0)

#define CHECK_EQ(a, b)                                                         \
    do {                                                                       \
        ++simpletest::checks();                                                \
        if (!((a) == (b))) {                                                   \
            ++simpletest::failures();                                          \
            std::cerr << "FAIL " << __FILE__ << ":" << __LINE__                \
                      << "  " << #a << " == " << #b << "\n";                   \
        }                                                                      \
    } while (0)

#define TEST_SUMMARY()                                                         \
    (simpletest::failures() == 0                                               \
         ? (std::cout << "All " << simpletest::checks()                        \
                      << " checks passed.\n", 0)                               \
         : (std::cerr << simpletest::failures() << " of "                      \
                      << simpletest::checks() << " checks FAILED.\n", 1))

#endif /* SIMPLETEST_H */
