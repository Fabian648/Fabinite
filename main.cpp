#include <SDL.h>
#include <iostream>
#include "Object.h"
#include "Log.h"
#include <windows.h>

//TODO Konsolen-Ausgabe möglich machen
//TODO Rechtecke verschieben
//TODO Rechtecke löschen

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Log-System initialisieren
    //create_log_system();

    // SDL2 initialisieren
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL konnte nicht initialisiert werden! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Erstelle ein Fenster
    SDL_Window* window = SDL_CreateWindow("Game Engine",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          1000, 1000, SDL_WINDOW_SHOWN);

    //TODO Abfrage von Betriebssystem SDL_SetWindowFullscreen funktioniert bloß in Windows
    //SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (!window) {
        std::cerr << "Fenster konnte nicht erstellt werden! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Render-Context erstellen
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //
    if (!renderer) {
        std::cerr << "Renderer konnte nicht erstellt werden! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Spiel-Schleife
    bool running = true;
    SDL_Event e;
    int mouseX, mouseY;

    while (running) {
        SDL_PumpEvents();
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) {
                running = false;
            }

            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_0:
                        // Ausgabe der Positionen der Rechtecke
                        for (size_t i = 0; i < list_rect.size(); i++) {
                            std::cout << "Index: " << i << "\n";
                            std::cout << "Rechteck X: " << list_rect[i].x << ", Y: " << list_rect[i].y << "\n";
                        }
                        break;
                    default:
                        //writelog_input(keyToString(e.key.keysym.sym));
                        break;
                }
            }

            // Mausklick überprüfen
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                // Mausposition erhalten
                SDL_GetMouseState(&mouseX, &mouseY);
                std::cout << "Linker Mausklick bei X: " << mouseX << ", Y: " << mouseY << std::endl;

                // Neues Rechteck erstellen
                create_rectangle(100, 100, mouseX, mouseY, renderer);
            }
        }

        // Hintergrundfarbe setzen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Schwarz
        SDL_RenderClear(renderer);

        // Rechtecke zeichnen
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Rot

        // Alle Rechtecke rendern
        for (const auto& rect : list_rect) {
            SDL_RenderFillRect(renderer, &rect);
        }

        // Anzeige aktualisieren
        SDL_RenderPresent(renderer);
    }

    // Ressourcen freigeben
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
