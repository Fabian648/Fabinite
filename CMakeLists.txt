# CMake Version festlegen
cmake_minimum_required(VERSION 3.12)

# Projektname
project(Engine)

# C++ Standard setzen
set(CMAKE_CXX_STANDARD 23)

# Setze den Pfad zu SDL2
set(SDL2_DIR "C:/Users/fabia/OneDrive/Dokumente/C/GameEngine/Engine/SDL2-2.30.9")

# SDL2 Header und Bibliotheken einbinden
include_directories(${SDL2_DIR}/include)
link_directories(${SDL2_DIR}/lib/x64)

# Füge alle Quellcodedateien hinzu
add_executable(Engine WIN32 main.cpp
        Object.cpp
        Object.h
        Log.cpp
        Log.h)

# SDL2 Bibliotheken verlinken
target_link_libraries(Engine SDL2)

# Kopiere SDL2.dll in das Build-Verzeichnis, um sicherzustellen, dass sie zur Laufzeit verfügbar ist
add_custom_command(TARGET Engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/Users/fabia/OneDrive/Dokumente/C/GameEngine/Engine/cmake-build-debug/SDL2.dll"
        "$<TARGET_FILE_DIR:Engine>/SDL2.dll"
)
