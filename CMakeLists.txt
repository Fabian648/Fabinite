cmake_minimum_required(VERSION 3.26)
project(Engine)

set(CMAKE_CXX_STANDARD 23)

# Setze den Pfad zu SDL2
set(SDL2_DIR "C:/Users/fabia/OneDrive/Dokumente/C/GameEngine/Engine/SDL2-2.30.9")

# SDL2 Header einbinden
include_directories(${SDL2_DIR}/include)

# SDL2-Bibliotheken einbinden (korrekter Pfad zu SDL2.lib)
link_directories(${SDL2_DIR}/lib/x64)

add_executable(Engine main.cpp
        Object.cpp
        Object.h
        Log.cpp
        Log.h
)

# SDL2-Bibliotheken verlinken
target_link_libraries(Engine SDL2)
