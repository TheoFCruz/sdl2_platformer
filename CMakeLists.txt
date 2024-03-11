cmake_minimum_required(VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(platformer)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB SOURCES ${SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

find_package(SDL2)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})

find_package(SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_image::SDL2_image)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_image_INCLUDE_DIRS})

find_package(SDL2_ttf)
target_link_libraries(${PROJECT_NAME} SDL2_ttf::SDL2_ttf)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_ttf_INCLUDE_DIRS})

