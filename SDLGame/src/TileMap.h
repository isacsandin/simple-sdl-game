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
#include <vector>
#include "Utils.h"
#include "Tile.h"
#include "Camera.h"

class TileMap {


	private:
	//The tiles that will be used
	vector<Tile *> tiles;

	//Sprite from the tile sheet
	vector<SDL_Rect> clipT;

	//The surface
	SDL_Surface *tileSheet;
	SDL_Surface *background;

	int screen_width;
	int screen_height;
	int number_of_scenes;
	int number_of_tiles;

public:
	TileMap( int width,  int height);

	bool set_tiles();

	void show(SDL_Surface *screen,Camera *camera);

	bool touches_wall( SDL_Rect box);

	int getNumberOfScenes();

	virtual ~TileMap();

};

#endif /* TILEMAP_H_ */
