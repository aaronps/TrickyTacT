/*
 *  SVideo.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SVideo.h"

SDL_Surface * SVideo::_video = 0;

bool
SVideo::setWindow(unsigned int width, unsigned int height, unsigned int bpp)
{
    _video = SDL_SetVideoMode(width, height, bpp, SDL_SWSURFACE);
    if ( ! _video )
    {
        return false;
    }
    
    return true;
}

