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
    static bool setWindow(unsigned int width, unsigned int height);
    
    static void update()
    {
        if ( _renderer )
            SDL_RenderPresent(_renderer);
    }
    
    static void blit(SSurface &from, int x, int y)
    {
        if ( ! _renderer )
            return;
        SDL_Rect r = {x,y,from.width,from.height};
        SDL_RenderCopy(_renderer, from._texture, 0, &r);
    }
    
    static void clear()
    {
        if ( _renderer )
        {
            SDL_SetRenderDrawColor( _renderer, 32, 96, 32, 0xff );
//            SDL_SetRenderDrawColor( _renderer, 32, 0, 32, 0xff );
            SDL_RenderClear(_renderer);
        }
    }
    
private:
    friend class SSurface;
    static SDL_Renderer * _renderer;
    static SDL_Window * _window;
};

#endif
