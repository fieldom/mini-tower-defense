cmake_minimum_required(VERSION 3.16)
project(MiniTowerDefense LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OXYGINE_DIR "$ENV{HOME}/projects/oxygine-framework")

add_subdirectory(${OXYGINE_DIR} oxygine_build)

add_executable(mini_tower_defense
    src/main.cpp
)

target_include_directories(mini_tower_defense PRIVATE
    ${OXYGINE_INCLUDE_DIRS}
)

target_link_libraries(mini_tower_defense PRIVATE
    ${OXYGINE_CORE_LIBS}
)
