cmake_minimum_required(VERSION 3.1.0)
project(test)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(SRC
    src/ImageDisplayer.cpp
    src/main.cpp
    src/MainMenu.cpp
    src/MainWindow.cpp
    src/PrenomDisplayer.cpp
    
)

set(HEADER
    headers/Context.hpp
    headers/ImageDisplayer.hpp
    headers/MainMenu.hpp
    headers/MainWindow.hpp
    headers/PrenomDisplayer.hpp
)

add_executable(main ${SRC} ${HEADER})
target_link_libraries(main Qt5::Widgets Qt5::Core Qt5::Gui)
