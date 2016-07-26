/*
 *  SEngine.h
 *  TrickyTacT
 *
 *  Created by krom on 1/17/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _SENGINE_H_
#define _SENGINE_H_

class SEngine
{
public:
    SEngine();
    ~SEngine();
    
    bool init();
    bool run();
    void quitEngine();
    const char * getErrorStr()
    {
        return _initErrorStr;
    }
    
private:
    bool _running;
    char * _initErrorStr;
};

#endif

