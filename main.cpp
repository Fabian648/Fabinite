#include <SDL.h>
#include <iostream>

int WinMain(int argc, char* argv[]) {
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
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
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
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        // Bildschirm löschen
        SDL_RenderClear(renderer);

        // Render-Zeichenoperationen
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Rot
        SDL_Rect fillRect = { 100, 100, 200, 150 };  // Rechteck
        SDL_RenderFillRect(renderer, &fillRect);

        // Anzeige aktualisieren
        SDL_RenderPresent(renderer);
    }

    // Ressourcen freigeben
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
