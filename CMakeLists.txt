cmake_minimum_required(VERSION 3.17)
project(DsaGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES "main.cpp" Game.cpp Game.h Player.cpp Player.h Blocks.cpp Blocks.h Enemy.cpp Enemy.h Captives.cpp Captives.h Sticks.cpp Sticks.h Bullets.cpp Bullets.h)
add_executable(DsaGame ${SOURCE_FILES})

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(DsaGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)