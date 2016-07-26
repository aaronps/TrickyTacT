/*
 *  SText.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SText.h"
#include "SDL.h"
#include "SVideo.h"

SText::FontArray SText::_fonts;

SText::SText()
{
    if ( !TTF_WasInit() )
        TTF_Init();
}

SText::~SText()
{
    FontIterator i = _fonts.begin();
    while ( i != _fonts.end() )
    {
        TTF_CloseFont(*i);
        ++i;
    }
    
    _fonts.clear();
    if ( TTF_WasInit() )
        TTF_Quit();
}

FontID
SText::LoadFont(const char * filename, int size)
{
    TTF_Font *f = TTF_OpenFont(filename, size);
    if (f) 
    {
        _fonts.insert(f);
    }
    return f;
}

void
SText::RenderScreen(int x, int y, FontID font, const char *str)
{
    SDL_Color c = {255,255,255,0};
    SSurface s(TTF_RenderText_Blended(font, str, c));
    SVideo::blit(s, x, y);
}
