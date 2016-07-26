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
        _texture = 0;
    }

    SSurface(const char * filename);
    SSurface(SDL_Surface *s);
    SSurface(SDL_Texture *t) : _texture(t) {}
    ~SSurface();
    
    void loadImage(const char * filename);
    void optimizeSurface();
    
private:
    friend class SVideo;
    SSurface(const SSurface &s) {}

    SDL_Texture * _texture;
    int width;
    int height;
};

#endif
