cmake_minimum_required(VERSION 3.1.0)
project(test)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

set(SRC
    main.cpp
)

set(HEADER
    fenetre.hpp

)

add_executable(main ${SRC} ${HEADER})
target_link_libraries(main Qt5::Widgets Qt5::Core Qt5::Gui)
