file(GLOB SOURCES "*.cpp")


target_sources(NotesApp PRIVATE
    ${SOURCES}
)

target_include_directories(NotesApp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})