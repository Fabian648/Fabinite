//
// Created by fabia on 21.11.2024.
//

#include "Object.h"

SDL_Rect create_rectangle(int width, int length, int x, int y,SDL_Renderer* render){
    SDL_RenderClear(render);
    SDL_Rect test = {x,y,width,length};

    //TODO HexCode Einlesen und in Farbcode umwandeln/vordefinierte Farben definieren
    SDL_SetRenderDrawColor(render,255,0,0,255);
    SDL_RenderFillRect(render, &test);
    return test;
}
