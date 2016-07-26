/*
 *  main.cpp
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "SEngine.h"
#include "SDL.h"
#include <cstdio>

int
main (int argc, char **argv)
{
    SEngine engine;
    
    if ( ! engine.init() )
    {
        fprintf(stderr, "ERROR!! Can't initialize engine: %s\n",
                engine.getErrorStr());
        return 1;
    }
    
    engine.run();
    
    return 0;
}

