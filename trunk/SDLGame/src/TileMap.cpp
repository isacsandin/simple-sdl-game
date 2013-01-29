/*
 * TileMap.cpp
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#include "TileMap.h"

TileMap::TileMap(int width, int height) {
	screen_width = width;
	screen_height = height;
	camera = new Camera(0, 0, width, height);
	tileSheet = Utils::load_image("resources/tiles.png");
	system("file resources/tiles.png");
	//Clip the sprite sheet
	clipT[TILE_RED].x = 0;
	clipT[TILE_RED].y = 0;
	clipT[TILE_RED].w = TILE_WIDTH;
	clipT[TILE_RED].h = TILE_HEIGHT;

	clipT[TILE_GREEN].x = 0;
	clipT[TILE_GREEN].y = 80;
	clipT[TILE_GREEN].w = TILE_WIDTH;
	clipT[TILE_GREEN].h = TILE_HEIGHT;

	clipT[TILE_BLUE].x = 0;
	clipT[TILE_BLUE].y = 160;
	clipT[TILE_BLUE].w = TILE_WIDTH;
	clipT[TILE_BLUE].h = TILE_HEIGHT;

	clipT[TILE_TOPLEFT].x = 80;
	clipT[TILE_TOPLEFT].y = 0;
	clipT[TILE_TOPLEFT].w = TILE_WIDTH;
	clipT[TILE_TOPLEFT].h = TILE_HEIGHT;

	clipT[TILE_LEFT].x = 80;
	clipT[TILE_LEFT].y = 80;
	clipT[TILE_LEFT].w = TILE_WIDTH;
	clipT[TILE_LEFT].h = TILE_HEIGHT;

	clipT[TILE_BOTTOMLEFT].x = 80;
	clipT[TILE_BOTTOMLEFT].y = 160;
	clipT[TILE_BOTTOMLEFT].w = TILE_WIDTH;
	clipT[TILE_BOTTOMLEFT].h = TILE_HEIGHT;

	clipT[TILE_TOP].x = 160;
	clipT[TILE_TOP].y = 0;
	clipT[TILE_TOP].w = TILE_WIDTH;
	clipT[TILE_TOP].h = TILE_HEIGHT;

	clipT[TILE_CENTER].x = 160;
	clipT[TILE_CENTER].y = 80;
	clipT[TILE_CENTER].w = TILE_WIDTH;
	clipT[TILE_CENTER].h = TILE_HEIGHT;

	clipT[TILE_BOTTOM].x = 160;
	clipT[TILE_BOTTOM].y = 160;
	clipT[TILE_BOTTOM].w = TILE_WIDTH;
	clipT[TILE_BOTTOM].h = TILE_HEIGHT;

	clipT[TILE_TOPRIGHT].x = 240;
	clipT[TILE_TOPRIGHT].y = 0;
	clipT[TILE_TOPRIGHT].w = TILE_WIDTH;
	clipT[TILE_TOPRIGHT].h = TILE_HEIGHT;

	clipT[TILE_RIGHT].x = 240;
	clipT[TILE_RIGHT].y = 80;
	clipT[TILE_RIGHT].w = TILE_WIDTH;
	clipT[TILE_RIGHT].h = TILE_HEIGHT;

	clipT[TILE_BOTTOMRIGHT].x = 240;
	clipT[TILE_BOTTOMRIGHT].y = 160;
	clipT[TILE_BOTTOMRIGHT].w = TILE_WIDTH;
	clipT[TILE_BOTTOMRIGHT].h = TILE_HEIGHT;

	//Set the tiles
	set_tiles();

}

bool TileMap::set_tiles() {
	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("resources/lazy.map");

	//If the map couldn't be loaded
	if (map == NULL) {
		return false;
	}

	//Initialize the tiles
	for (int t = 0; t < TOTAL_TILES; t++) {
		//Determines what kind of tile will be made
		int tileType = -1;

		//Read tile from map file
		map >> tileType;

		//If the was a problem in reading the map
		if (map.fail() == true) {
			//Stop loading map
			map.close();
			return false;
		}

		//If the number is a valid tile number
		if ((tileType >= 0) && (tileType < TILE_SPRITES)) {
			tiles[t] = new Tile(x, y, TILE_WIDTH, TILE_HEIGHT, tileType);
		}
		//If we don't recognize the tile type
		else {
			//Stop loading map
			map.close();
			return false;
		}

		//Move to next tile spot
		x += TILE_WIDTH;

		//If we've gone too far
		if (x >= screen_width) {
			//Move back
			x = 0;

			//Move to the next row
			y += TILE_HEIGHT;
		}
	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return true;
}

void TileMap::show(SDL_Surface *screen) {
	for (int t = 0; t < TOTAL_TILES; t++) {
		if (Utils::check_collision(camera->getCamera(), tiles[t]->getBox())
				== true) {
			//Show the tile
			Utils::apply_surface(tiles[t]->getBox().x - camera->getCamera().x,
					tiles[t]->getBox().y - camera->getCamera().y, tileSheet,
					screen, &clipT[tiles[t]->getType()]);
		}
	}
}

bool TileMap::touches_wall(SDL_Rect box) {
	//Go through the tiles
	for (int t = 0; t < TOTAL_TILES; t++) {
		//If the tile is a wall type tile
		if ((tiles[t]->getType() >= TILE_CENTER)
				&& (tiles[t]->getType() <= TILE_TOPLEFT)) {
			//If the collision box touches the wall tile
			if (Utils::check_collision(box, tiles[t]->getBox()) == true) {
				return true;
			}
		}
	}

	//If no wall tiles were touched
	return false;
}

TileMap::~TileMap() {
	// TODO Auto-generated destructor stub
}

