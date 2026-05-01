cmake_minimum_required(VERSION 3.19)
project(NotesApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_standard_project_setup()

qt_add_executable(NotesApp
    WIN32 MACOSX_BUNDLE
    main.cpp
)

qt_add_qml_module(NotesApp
    URI App
    VERSION 1.0
    QML_FILES Main.qml
)

add_subdirectory(src)

target_link_libraries(NotesApp
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
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