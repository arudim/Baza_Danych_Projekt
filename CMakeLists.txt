cmake_minimum_required(VERSION 3.19)
project(Baza_Danych LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Baza_Danych
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ksiazka.h ksiazka.cpp
    film.h film.cpp
    BazaDanych.h BazaDanych.cpp
    dodawanie_rekordu.h dodawanie_rekordu.cpp dodawanie_rekordu.ui



)

target_link_libraries(Baza_Danych
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Baza_Danych
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Baza_Danych
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
