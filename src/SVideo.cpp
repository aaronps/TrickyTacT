/*
 *  SVideo.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SVideo.h"

SDL_Renderer * SVideo::_renderer = 0;
SDL_Window * SVideo::_window = 0;

bool
SVideo::setWindow(unsigned int width, unsigned int height)
{
   _window = SDL_CreateWindow(  "TrickyTacT2",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                480, 800,
//                                800, 480,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    if ( ! _window )
    {
        return false;
    }
    
   _renderer = SDL_CreateRenderer(_window, -1, 0);
   SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
   SDL_RenderSetLogicalSize(_renderer,width, height);
   
    return true;
}

