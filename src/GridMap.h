/*
 *  GridMap.h
 *  TrickyTacT
 *
 *  Created by krom on 1/19/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _GRIDMAP_H_
#define _GRIDMAP_H_

#include <cstdio>
#include "SVideo.h"

class GridMap
{
public:
    GridMap()
        : _grid("images/grid.png"),
          _circle("images/o.png"),
          _ex("images/x.png"),
          _remaining_moves(9),
          _winner(0)
    {
        memset(_map, 0, sizeof(_map));
        memset(_setmap, 0, sizeof(_setmap));
    }
    
    void reset()
    {
        _remaining_moves = 9;
        _winner = 0;
        memset(_map, 0, sizeof(_map));
        memset(_setmap, 0, sizeof(_setmap));        
    }
    
    ~GridMap() {}

    void blitToVideo()
    {
        SVideo::blit(_grid,200,150);
        int x;
        int y;
        for (y = 0; y < 3; ++y)
        {
            for (x=0; x < 3; ++x)
            {
                if ( _setmap[y][x] )
                {
                    if ( _map[y][x] )
                    {
                        SVideo::blit(_ex,210+(x*130),160+(y*130));                        
                    } else {
                        SVideo::blit(_circle,210+(x*130),160+(y*130));                        
                    }
                }
            }
        }
    }
    
    bool setMark(unsigned int x, unsigned int y, char value)
    {
        if ( !hasRemainingMoves() || x >= 3 || y >= 3 || value > 1 || _setmap[y][x] )
            return false;
        
        _map[y][x] = value;
        _setmap[y][x] = true;
        --_remaining_moves;
        return true;
    }
    
    bool hasRemainingMoves() { return _remaining_moves > 0;  }
    
    int getRemainingMoves() { return _remaining_moves; }
    
    bool checkWin()
    {
        int c;
        for ( c = 0; c < 3; c++ )
        {
            if ( isHLine(c) )
            {
                _winner = _map[c][0];
                _remaining_moves = 0;
                return true;
            }
            else if ( isVLine(c) )
            {
                _winner = _map[0][c];
                _remaining_moves = 0;
                return true;
            }
        }
        
        if ( _setmap[0][0] && _setmap[1][1] && _setmap[2][2]
            && _map[0][0] == _map[1][1] && _map[0][0] == _map[2][2])
        {
            _winner = _map[0][0];
            _remaining_moves = 0;
            return true;
        }
        
        if ( _setmap[2][0] && _setmap[1][1] && _setmap[0][2]
            && _map[2][0] == _map[1][1] && _map[2][0] == _map[0][2])
        {
            _winner = _map[2][0];
            _remaining_moves = 0;
            return true;
        }
        
        return false;
    }
    
    int getWinner()
    {
        return _winner;
    }

private:
    bool isHLine(int line)
    {
        return _setmap[line][0] && _setmap[line][1] && _setmap[line][2]
            && _map[line][0] == _map[line][1] && _map[line][0]==_map[line][2];
    }

    bool isVLine(int column)
    {
        return _setmap[0][column] && _setmap[1][column] && _setmap[2][column]
        && _map[0][column] == _map[1][column] && _map[0][column]==_map[2][column];
    }
    
    char _map[3][3];
    bool _setmap[3][3];
    int _remaining_moves;
    SSurface _grid;
    SSurface _circle;
    SSurface _ex;
    int _winner;
};

#endif
