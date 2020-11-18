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
    src/main.cc
    src/fenetre.cc
    src/bouton.cc
    src/affichage.cc
)

set(HEADER
    header/fenetre.hh
    header/bouton.hh
    header/affichage.hh
)

set(ImageFileReader_HEADERS 
    header/bouton.hh
)

QT5_WRAP_CPP(ImageFileReader_HEADERS_MOC ${ImageFileReader_HEADERS})

add_executable(main ${SRC} ${HEADER} ${ImageFileReader_HEADERS_MOC})
target_link_libraries(main Qt5::Widgets Qt5::Core Qt5::Gui)
