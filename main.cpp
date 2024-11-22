#include <SDL.h>
#include <iostream>
#include "Object.h"
#include "Log.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Log-System initialisieren
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
    int mouseX, mouseY;

    while (running) {
        // Event-Handling
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //SDL_PumpEvents();


        // Hintergrundfarbe setzen


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
                        // Ausgabe der Positionen der Rechtecke
                        for (size_t i = 0; i < list_rect.size(); i++) {
                            std::cout << "Index: " << i << "\n";
                            std::cout << "Rechteck X: " << list_rect[i].x << ", Y: " << list_rect[i].y << "\n";
                        }
                        break;
                    default:
                        writelog_input(keyToString(e.key.keysym.sym));
                        break;
                }
            }

            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                // Mausposition speichern
                SDL_GetMouseState(&mouseX, &mouseY);
                std::cout << "Klick bei X: " << mouseX << ", Y: " << mouseY << std::endl;

                // Neues Rechteck erstellen und zu list_rect hinzufügen
                SDL_Rect new_rect = create_rectangle(100, 100, mouseX, mouseY, renderer);
            }
        }
        //Test
        //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Rot
        //SDL_Rect fillRect = { 100, 100, 200, 150 };  // Rechteck
        //SDL_RenderFillRect(renderer, &fillRect);

        // Alle Rechtecke zeichnen
        for (size_t i = 0; i < list_rect.size(); i++) {

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Setze Farbe für das Rechteck (Rot)
            SDL_RenderFillRect(renderer, &list_rect[i]); // Rechteck zeichnen
        }



        SDL_RenderPresent(renderer); // Zeichnen anzeigen
    }

    // Ressourcen freigeben
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
