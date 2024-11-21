//
// Created by fabia on 21.11.2024.
//
#include "SDL_rect.h"
#include "SDL_render.h"

#define MAX 255


#ifndef ENGINE_OBJECT_H
#define ENGINE_OBJECT_H

extern SDL_Rect list_rect [MAX];
extern int rect_num;

// functions
SDL_Rect create_rectangle(int width, int length, int x, int y, SDL_Renderer* render);
#endif //ENGINE_OBJECT_H
