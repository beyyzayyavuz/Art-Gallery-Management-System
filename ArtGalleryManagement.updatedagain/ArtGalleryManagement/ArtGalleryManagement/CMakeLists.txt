cmake_minimum_required(VERSION 3.10)
project(ArtGalleryManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Core library: all logic except the program entry point. Both the app and the
# test runner link against this, so logic is compiled once and tested directly.
add_library(gallery_core STATIC
    Artist.cpp
    Exhibition.cpp
    Painting.cpp
    Visitor1.cpp
    Admin.cpp
    GalleryStaff.cpp
    user.cpp
    Gallery.cpp
    Console.cpp
)
target_include_directories(gallery_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Application executable
add_executable(ArtGalleryManagement ArtGalleryManagement.cpp)
target_link_libraries(ArtGalleryManagement PRIVATE gallery_core)

# Unit tests
enable_testing()
add_executable(unit_tests tests/tests.cpp)
target_link_libraries(unit_tests PRIVATE gallery_core)
add_test(NAME unit_tests COMMAND unit_tests)
