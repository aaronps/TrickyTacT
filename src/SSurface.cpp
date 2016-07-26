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
#include "SVideo.h"
#include "stdio.h"

SSurface::SSurface(const char *filename)
{
    _texture = 0;
    loadImage(filename);
}

SSurface::SSurface(SDL_Surface* s)
{
    width = s->w;
    height = s->h;
    _texture = SDL_CreateTextureFromSurface(SVideo::_renderer, s);
    SDL_FreeSurface(s);
}

SSurface::~SSurface()
{
    if ( _texture )
        SDL_DestroyTexture(_texture);
    _texture = 0;
}

void
SSurface::loadImage(const char * filename)
{
    if ( _texture )
        SDL_DestroyTexture(_texture);
    
    _texture = 0;
    SDL_Surface * s = IMG_Load(filename);
    if ( s )
    {
        width = s->w;
        height = s->h;
        _texture = SDL_CreateTextureFromSurface(SVideo::_renderer, s);
        SDL_FreeSurface(s);
    }
    else
    {
        printf("Error loading image '%s'\n", filename);
    }
}

void
SSurface::optimizeSurface()
{
//    if ( _surface )
//    {
//        SDL_Surface * t = SDL_DisplayFormat(_surface);
//        if ( t )
//        {
//            SDL_FreeSurface(_surface);
//            _surface = t;
//        }
//    }
}
