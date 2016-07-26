/*
 *  SVideo.h
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _SVIDEO_H_
#define _SVIDEO_H_

#include "SDL.h"
#include "SSurface.h"

class SVideo
{
public:
    static bool setWindow(unsigned int width, unsigned int height, unsigned int bpp);
    
    static void update()
    {
        if ( _video )
            SDL_UpdateRect(_video, 0, 0, 0, 0);
    }
    
    static void blit(SSurface &from, int x, int y)
    {
        if ( ! _video )
            return;
        SDL_Rect r = {x,y,0,0};
        SDL_BlitSurface(from._surface, 0, _video, &r);        
    }
    
    static void clear()
    {
        if ( _video )
        {
            SDL_FillRect(_video, 0, 0);
        }
    }
    
private:
    static SDL_Surface * _video;
};

#endif
