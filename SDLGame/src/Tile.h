/*
 * Tile.h
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#ifndef TILE_H_
#define TILE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <fstream>
#include "Utils.h"

class Tile
{
//	public:
//	const int DOT_WIDTH = 20;
//	const int DOT_HEIGHT = 20;
    private:
    //The attributes of the tile
    SDL_Rect box;
    int type;

    public:
    //Initializes the variables
    Tile (int x, int y, int tile_width, int tile_height, int type );

    //Shows the tile
    void show(SDL_Surface *screen);

//    void move(Tile *tiles[]);

    //Get the tile type
    int getType();

    //Get the collision box
    SDL_Rect getBox();

	virtual ~Tile();

};


#endif /* TILE_H_ */
