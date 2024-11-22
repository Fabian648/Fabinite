//
// Created by fabia on 21.11.2024.
//
//TODO Fehler finden - Log System hat Rechteck rendering blockiert
#include "Log.h"

namespace fs = std::filesystem;
fs::path dir_path = getExecutablePath()+"\\log";
fs::path input_path = getExecutablePath()+"\\log\\input.log";
fs::path error_path = getExecutablePath()+"\\log\\error.log";

//Funktion um aktuellen Ordner zu finden
std::string getExecutablePath() {
    char buffer[MAX_PATH];
    if (GetModuleFileNameA(NULL, buffer, MAX_PATH) != 0) {
        std::string fullPath(buffer);
        fs::path path(fullPath);
        return path.parent_path().string();
    } else {
        return "Fehler";  // Fehler beim Abrufen des Pfads
    }
}

void create_log_system(){
    if(!fs::exists(dir_path)){
        if(fs::create_directory(dir_path)){
            std::cout << "Log-Ordner erstellt" << std::endl;
        }else{
            std::cout << "Fehler beim Log-Ordner erstellen" << std::endl;
        }
    }

    if(!fs::exists(error_path)){
        std::ofstream ofs(error_path);
        ofs.close();
    }
    if(!fs::exists(input_path)){
        std::ofstream ofs(input_path);
        ofs.close();
    }
}

void writelog_error(std::string message){
    time_t timestamp;
    time(&timestamp);

    std::ofstream datei(error_path, std::ios::app);

    if (!datei.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << error_path << std::endl;
    }else {

        datei << "Neuer Text wird hinzugefügt!\n";
        datei.close();
    }
}

void writelog_input(std::string message){
    time_t timestamp;
    time(&timestamp);

    std::ofstream datei(input_path, std::ios::app);

    if (!datei.is_open()) {
        std::cerr << "Fehler beim Öffnen der Datei: " << input_path << std::endl;
    }else {

        datei << ctime(&timestamp) << message << "\n";
        datei.close();
    }
}

std::string keyToString(SDL_Keycode key) {
    switch (key) {
        case SDLK_a: return "a";
        case SDLK_b: return "b";
        case SDLK_c: return "c";
        case SDLK_d: return "d";
        case SDLK_e: return "e";
        case SDLK_f: return "f";
        case SDLK_g: return "g";
        case SDLK_h: return "h";
        case SDLK_i: return "i";
        case SDLK_j: return "j";
        case SDLK_k: return "k";
        case SDLK_l: return "l";
        case SDLK_m: return "m";
        case SDLK_n: return "n";
        case SDLK_o: return "o";
        case SDLK_p: return "p";
        case SDLK_q: return "q";
        case SDLK_r: return "r";
        case SDLK_s: return "s";
        case SDLK_t: return "t";
        case SDLK_u: return "u";
        case SDLK_v: return "v";
        case SDLK_w: return "w";
        case SDLK_x: return "x";
        case SDLK_y: return "y";
        case SDLK_z: return "z";
        case SDLK_1: return "1";
        case SDLK_2: return "2";
        case SDLK_3: return "3";
        case SDLK_4: return "4";
        case SDLK_5: return "5";
        case SDLK_6: return "6";
        case SDLK_7: return "7";
        case SDLK_8: return "8";
        case SDLK_9: return "9";
        case SDLK_0: return "0";
        case SDLK_SPACE: return "Space";
        case SDLK_RETURN: return "Enter";
        case SDLK_ESCAPE: return "Escape";
        case SDLK_LEFT: return "Left Arrow";
        case SDLK_RIGHT: return "Right Arrow";
        case SDLK_UP: return "Up Arrow";
        case SDLK_DOWN: return "Down Arrow";
            // Füge hier weitere Tasten hinzu, falls nötig.
        default: return "Unknown Key";
    }
}