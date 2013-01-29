/*
 * Tile.cpp
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#include "Tile.h"


Tile::Tile( int x, int y,  int tile_width, int tile_height, int tType)
{
    //Get the offsets
    box.x = x;
    box.y = y;

    //Set the collision box
    box.w = tile_width;
    box.h = tile_height;

    //Get the tile type
    type = tType;
}


void Tile::show(SDL_Surface *screen)
{
}

SDL_Rect Tile::getBox()
{
    return box;
}
/*
void Tile::move(Tile *tiles[] ){
	//Move the dot left or right
	    box.x += xVel;

	    //If the dot went too far to the left or right or touched a wall
	    if( ( box.x < 0 ) || ( box.x + DOT_WIDTH > 640 ) || touches_wall( box, tiles ) )
	    {
	        //move back
	        box.x -= xVel;
	    }

	    //Move the dot up or down
	    box.y += yVel;

	    //If the dot went too far up or down or touched a wall
	    if( ( box.y < 0 ) || ( box.y + DOT_HEIGHT > 640 ) || touches_wall( box, tiles ) )
	    {
	        //move back
	        box.y -= yVel;
	    }
}
*/


int Tile::getType()
{
    return type;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}


