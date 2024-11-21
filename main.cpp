#include <SDL.h>
#include <iostream>
#include "Object.h"
#include "Log.h"

//int main(int argc, char* argv[]) {
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    //Log-System initalisieren
    create_log_system();

    // SDL2 initialisieren
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL konnte nicht initialisiert werden! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Erstelle ein Fenster
    SDL_Window* window = SDL_CreateWindow("Game Engine",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          800, 600, SDL_WINDOW_SHOWN);

    //TODO Abfrage von Betriebssystem SDL_SetWindowFullscreen funktioniert bloß in Windows
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (!window) {
        std::cerr << "Fenster konnte nicht erstellt werden! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Render-Context erstellen
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer konnte nicht erstellt werden! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Spiel-Schleife
    bool running = true;
    SDL_Event e;
    while (running) {
        // Event-Handling
        SDL_PumpEvents();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        running = false;
                        break;

                    case SDLK_0:

                        break;
                    default:
                        //TODO Log-File System
                        //std::cout << "Taste gedrueckt: " << e.key.keysym.sym << std::endl;
                        writelog_input(keyToString(e.key.keysym.sym));
                        break;
                }
            }
        }

        // Bildschirm löschen
        SDL_RenderClear(renderer);

        // Render-Zeichenoperationen-Hintergrund
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Rot
        SDL_RenderClear(renderer);

        SDL_Rect test = create_rectangle(100,100,30,30,renderer);
        SDL_RenderPresent(renderer);

    }

    // Ressourcen freigeben
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
