/*
 *  SSurface.h
 *  TrickyTacT
 *
 *  Created by krom on 1/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SSURFACE_H_
#define _SSURFACE_H_

#include "SDL.h"

class SSurface
{
public:
    SSurface()
    {
        _surface = 0;
    }

    SSurface(const char * filename);
    SSurface(SDL_Surface *s) : _surface(s) {}
    ~SSurface();
    
    void loadImage(const char * filename);
    void optimizeSurface();
    void blitFrom(SSurface & from, int x, int y);
    
private:
    friend class SVideo;
    SSurface(const SSurface &s) {}

    SDL_Surface * _surface;
};

#endif
