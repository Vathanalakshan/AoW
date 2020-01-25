cmake_minimum_required(VERSION 3.15)
project(AoW)

set(CMAKE_CXX_STANDARD 14)

add_executable(AoW main.cpp Fantassin.h Unit.h Battlefield.cpp Battlefield.h Player.cpp Player.h Unit.cpp Fantassin.cpp Archer.cpp Archer.h Catapulte.cpp Catapulte.h Fort.cpp Fort.h Case.cpp Case.h)