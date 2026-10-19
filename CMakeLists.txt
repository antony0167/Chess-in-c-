cmake_minimum_required(VERSION 3.16)
project(Chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Use an installed SFML 2.5/2.6 if there is one, otherwise download and build it.
find_package(SFML 2.5 COMPONENTS graphics window system QUIET)
if(NOT SFML_FOUND)
    message(STATUS "SFML not found, fetching it")
    include(FetchContent)
    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.1)
    set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
    set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(SFML)
endif()

add_executable(chess main.cpp)
target_link_libraries(chess PRIVATE sfml-graphics sfml-window sfml-system)

# piece images are looked up next to the executable
target_compile_definitions(chess PRIVATE IMAGES_DIR="images")
add_custom_command(TARGET chess POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/images $<TARGET_FILE_DIR:chess>/images)
