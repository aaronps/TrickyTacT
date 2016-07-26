/*
 *  SSurface.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SSurface.h"
#include "SDL.h"
#include "SDL_image.h"

SSurface::SSurface(const char *filename)
{
    _surface = 0;
    loadImage(filename);
}

SSurface::~SSurface()
{
    if ( _surface )
        SDL_FreeSurface(_surface);
    _surface = 0;
}

void
SSurface::loadImage(const char * filename)
{
    if ( _surface )
        SDL_FreeSurface(_surface);
    
    _surface = IMG_Load(filename);
}

void
SSurface::optimizeSurface()
{
    if ( _surface )
    {
        SDL_Surface * t = SDL_DisplayFormat(_surface);
        if ( t )
        {
            SDL_FreeSurface(_surface);
            _surface = t;
        }
    }
}

void
SSurface::blitFrom(SSurface &from, int x, int y)
{
    if ( ! _surface )
        return;
    SDL_Rect r = {x,y,0,0};
    SDL_BlitSurface(from._surface,0,_surface,&r);
}
