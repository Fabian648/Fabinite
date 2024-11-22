//
// Created by fabia on 21.11.2024.
//

#include "Object.h"

//SDL_Rect list_rect [MAX] = {};
std::vector<SDL_Rect> list_rect;
int rect_num = 0;
/*
SDL_Rect create_rectangle(int width, int length, int x, int y,SDL_Renderer* render){
    SDL_Rect rect = {x,y,width,length};

    //TODO HexCode Einlesen und in Farbcode umwandeln/vordefinierte Farben definieren
    SDL_SetRenderDrawColor(render,255,0,0,255);
    SDL_RenderFillRect(render, &rect);
    return rect;
}
 */
/*
SDL_Rect create_rectangle(int width, int length, int x, int y, SDL_Renderer* render) {
    // Berechnung der Position des Rechtecks, sodass der Mauszeiger in der Mitte des Rechtecks bleibt
    int rect_x = x - width / 2;  // Versatz für die Mitte des Rechtecks
    int rect_y = y - length / 2; // Versatz für die Mitte des Rechtecks

    // Verhindere, dass das Rechteck außerhalb des Fensters gezeichnet wird (Begrenzung auf Bildschirmgröße)
    rect_x = std::max(0, rect_x); // Stellen Sie sicher, dass X nicht negativ ist
    rect_y = std::max(0, rect_y); // Stellen Sie sicher, dass Y nicht negativ ist

    // Bildschirmgröße (falls du das Fenster auf 800x600 festgelegt hast)
    int screen_width = 800;
    int screen_height = 600;

    // Verhindern, dass das Rechteck den Bildschirmbereich überschreitet
    if (rect_x + width > screen_width) {
        rect_x = screen_width - width;
    }

    if (rect_y + length > screen_height) {
        rect_y = screen_height - length;
    }

    SDL_Rect rect = {rect_x, rect_y, width, length};

    // Rechteck zeichnen (rote Farbe)
    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    SDL_RenderFillRect(render, &rect);

    list_rect.push_back(rect);
    rect_num++; // Erhöhe den Zähler
    std::cout << "Rechteck zu Index " << rect_num - 1 << " hinzugefügt. Gesamtzahl: " << rect_num << std::endl;


    return rect;
}
*/