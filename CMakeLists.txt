cmake_minimum_required(VERSION 3.19)
project(NotesApp LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(NotesApp
    WIN32 MACOSX_BUNDLE
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    main.cpp
)

add_subdirectory(src)

target_link_libraries(NotesApp
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS NotesApp
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET NotesApp
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
