cmake_minimum_required(VERSION 3.1)
project("widgets_project")

#set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "/home/projects/snake/SFML")

find_package(SFML 2 COMPONENTS audio graphics window system REQUIRED)

set(SOURCES
    src/main.cpp
    src/Gui.cpp
    src/Widget.cpp
    src/Button.cpp
    src/Picture.cpp
)

add_executable(widgets ${SOURCES})

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${PROJECT_SOURCE_DIR}/resources 
    ${PROJECT_BINARY_DIR}/resources 
    COMMENT "Copying resources into binary directory"
)

add_dependencies(widgets copy_resources)

target_include_directories(widgets PUBLIC include)
target_link_libraries(widgets sfml-graphics sfml-audio)