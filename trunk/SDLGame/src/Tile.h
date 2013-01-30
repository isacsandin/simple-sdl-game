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

class Tile {
	//Tile constants
public:
	static const int TILE_WIDTH = 40;
	static const int TILE_HEIGHT = 40;

	//The different tile sprites
	static const int TILE_RED = 0;
	static const int TILE_GREEN = 1;
	static const int TILE_BLUE = 2;
	static const int TILE_CENTER = 3;
	static const int TILE_TOP = 4;
	static const int TILE_TOPRIGHT = 5;
	static const int TILE_RIGHT = 6;
	static const int TILE_BOTTOMRIGHT = 7;
	static const int TILE_BOTTOM = 8;
	static const int TILE_BOTTOMLEFT = 9;
	static const int TILE_LEFT = 10;
	static const int TILE_TOPLEFT = 11;
	static const int TILE_BACKGROUND = 12;
	static const int NUMBER_OF_TILE_TYPES = 13;

	Tile(int x, int y, int tile_width, int tile_height, int type);
	void show(SDL_Surface *screen);
	void move(Tile *tiles[]);
	int getType();
	SDL_Rect getBox();
	virtual ~Tile();

private:
	SDL_Rect box;
	int type;

};

#endif /* TILE_H_ */
