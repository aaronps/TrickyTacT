/*
 *  SText.h
 *  TrickyTacT
 *
 *  Created by krom on 1/20/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _STEXT_H
#define _STEXT_H

#include <set>
#include "SDL_ttf.h"

using namespace std;

typedef TTF_Font * FontID;

class SText
{
public:
    SText();
    ~SText();
    
    static FontID LoadFont(const char * filename, int size);
    static void RenderScreen(int x, int y, FontID font, const char *str);
    
private:
    typedef set<TTF_Font *> FontArray;
    typedef FontArray::iterator FontIterator;
    static FontArray _fonts;
};

#endif
