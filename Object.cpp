//
// Created by fabia on 21.11.2024.
//

#include "Object.h"

std::vector<SDL_Rect> list_rect;
int rect_num = 0;
SDL_Rect rect = {};

//TODO Funktion erweitern zu Farbe
const SDL_Rect * create_rectangle(int width, int length, int x, int y, SDL_Renderer* render) {

    //rect = {x: rect_x, y: rect_y, w:width, h:length};
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = length;

    list_rect.push_back(rect);
    rect_num++; // Erhöhe den Zähler
    std::cout << "Rechteck erstellt: ("
              << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h
              << ") - Gesamtanzahl: " << list_rect.size() << std::endl;

    return &rect;
}