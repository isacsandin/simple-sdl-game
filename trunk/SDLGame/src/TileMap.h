/*
 * TileMap.h
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <fstream>
#include "Utils.h"
#include "Tile.h"
#include "Camera.h"

class TileMap {

	public:
	//Tile constants
	static const int TILE_WIDTH = 40;
	static const int TILE_HEIGHT = 40;
	static const int TOTAL_TILES = 192;
	static const int TILE_SPRITES = 12;


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
	private:
	//The tiles that will be used
	Tile *tiles[ TOTAL_TILES ];
	//Sprite from the tile sheet
	SDL_Rect clipT[ TILE_SPRITES ];
	//The surface
	SDL_Surface *tileSheet;

	Camera *camera;

	int screen_width;
	int screen_height;

public:
	TileMap( int width,  int height);

	bool set_tiles();

	void show(SDL_Surface *screen);

	bool touches_wall( SDL_Rect box);

	virtual ~TileMap();

};

#endif /* TILEMAP_H_ */
