//
// Created by fabia on 21.11.2024.
//
#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H

#include "SDL_keycode.h"
#include <string>
#include <filesystem>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>


//function
void create_log_system();
void writelog_error(std::string message);
void writelog_input(std::string message);
std::string keyToString(SDL_Keycode key);
std::string getExecutablePath();


#endif //ENGINE_LOG_H
