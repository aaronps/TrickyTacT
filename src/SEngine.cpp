/*
 *  SEngine.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SEngine.h"
#include "SVideo.h"
#include "SSurface.h"
#include "SDL.h"
#include "GridMap.h"
#include "SText.h"
#include <cstdlib>
#include <cstdio>

/* Constructor initializes only variables */
SEngine::SEngine()
{
    _running = true;
    _initErrorStr = 0;
}

/* Destructor finish things */
SEngine::~SEngine()
{
    SDL_Quit();
}

/* Initialize libraries and engine */
bool
SEngine::init()
{
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
    {
        _initErrorStr = SDL_GetError();
        return false;
    }
    
    SVideo::setWindow(800,600,0);
    
    return true;
}

/* Main game loop is here */
bool
SEngine::run()
{
    SText _text;
    SDL_Event event;
    SSurface s("images/title.png");
    GridMap grid;
    FontID font;
    srandom(SDL_GetTicks());
    bool aimove = random()&random()&1;
    font = SText::LoadFont("images/Vera.ttf", 24 );
    
    while (_running)
    {
        SVideo::clear();
        SVideo::blit(s,100,000);
        
        if ( aimove && grid.hasRemainingMoves() && !grid.checkWin() ) // bot move
        {
            bool moved = false;
             
            do {
                long r = random();
                moved = grid.setMark(r&3, (r>>2)&3, 1);
            } while ( ! moved );
            aimove = false;
        }
        
        grid.blitToVideo();
        if ( grid.checkWin() )
        {
            if ( grid.getWinner() )
            {
                SText::RenderScreen( 350, 290, font, "Computer Wins");
            }
            else
            {
                SText::RenderScreen( 350, 290, font, "You Win");
            }
        }
        else if ( ! grid.hasRemainingMoves() )
        {
            SText::RenderScreen( 350, 290, font, "Draw");
        }
        
        SText::RenderScreen( 275, 550, font, "Press Enter To Restart");
        
        SVideo::update();
        SDL_WaitEvent(&event);
        {
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    if (    event.button.x > 205 && event.button.x < 595
                         && event.button.y > 155 && event.button.y < 545 )
                    {
                        int px = event.button.x - 205;
                        int py = event.button.y - 155;
                        int gx = px / 130;
                        int gy = py / 130;
                        if ( grid.setMark(gx,gy,0) )
                        {
                            aimove = true;
                        }
                    }
                    
                    break;
                case SDL_KEYDOWN:
                    switch ( event.key.keysym.sym )
                    {
                        case SDLK_RETURN:
                            grid.reset();
                            break;
                        case SDLK_ESCAPE:
                            quitEngine();
                            break;
                    }
                    break;
                case SDL_QUIT:
                    quitEngine();
            }
        }
    }
    

    return true;
}

/* signals engine loop to quit */
void
SEngine::quitEngine()
{
    _running = false;
}