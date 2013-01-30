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
	number_of_scenes = 0;
	number_of_tiles = 0;
	tileSheet = Utils::load_image("resources/tiles.png");
	background = Utils::load_image("resources/background.png");

	clipT.reserve(Tile::NUMBER_OF_TILE_TYPES);

	//Clip the sprite sheet
	clipT[Tile::TILE_RED].x = 0;
	clipT[Tile::TILE_RED].y = 0;
	clipT[Tile::TILE_RED].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_RED].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_GREEN].x = 0;
	clipT[Tile::TILE_GREEN].y = 80;
	clipT[Tile::TILE_GREEN].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_GREEN].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_BLUE].x = 0;
	clipT[Tile::TILE_BLUE].y = 160;
	clipT[Tile::TILE_BLUE].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_BLUE].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_TOPLEFT].x = 80;
	clipT[Tile::TILE_TOPLEFT].y = 0;
	clipT[Tile::TILE_TOPLEFT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_TOPLEFT].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_LEFT].x = 80;
	clipT[Tile::TILE_LEFT].y = 80;
	clipT[Tile::TILE_LEFT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_LEFT].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_BOTTOMLEFT].x = 80;
	clipT[Tile::TILE_BOTTOMLEFT].y = 160;
	clipT[Tile::TILE_BOTTOMLEFT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_BOTTOMLEFT].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_TOP].x = 160;
	clipT[Tile::TILE_TOP].y = 0;
	clipT[Tile::TILE_TOP].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_TOP].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_CENTER].x = 160;
	clipT[Tile::TILE_CENTER].y = 80;
	clipT[Tile::TILE_CENTER].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_CENTER].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_BOTTOM].x = 160;
	clipT[Tile::TILE_BOTTOM].y = 160;
	clipT[Tile::TILE_BOTTOM].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_BOTTOM].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_TOPRIGHT].x = 240;
	clipT[Tile::TILE_TOPRIGHT].y = 0;
	clipT[Tile::TILE_TOPRIGHT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_TOPRIGHT].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_RIGHT].x = 240;
	clipT[Tile::TILE_RIGHT].y = 80;
	clipT[Tile::TILE_RIGHT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_RIGHT].h = Tile::TILE_HEIGHT;

	clipT[Tile::TILE_BOTTOMRIGHT].x = 240;
	clipT[Tile::TILE_BOTTOMRIGHT].y = 160;
	clipT[Tile::TILE_BOTTOMRIGHT].w = Tile::TILE_WIDTH;
	clipT[Tile::TILE_BOTTOMRIGHT].h = Tile::TILE_HEIGHT;

	//Set the tiles
	set_tiles();

}

bool TileMap::set_tiles() {
	//The tile offsets
	int x = 0, y = 0;

	//Open the map
	std::ifstream map("resources/back.map");

	//If the map couldn't be loaded
	if (map == NULL) {
		return false;
	}

	map >> number_of_scenes;
	if(number_of_scenes <= 0) return false;

	int tiles_per_height = screen_height/Tile::TILE_HEIGHT;

	int tiles_per_width = screen_width/Tile::TILE_WIDTH;

	number_of_tiles = tiles_per_height * number_of_scenes * tiles_per_width;

	tiles.reserve(number_of_tiles);

	//Initialize the tiles
	for (int t = 0; t < number_of_tiles; t++) {
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
		if ((tileType >= 0) && (tileType < Tile::NUMBER_OF_TILE_TYPES)) {
			tiles[t] = new Tile(x, y, Tile::TILE_WIDTH, Tile::TILE_HEIGHT, tileType);
		}
		//If we don't recognize the tile type
		else {
			//Stop loading map
			map.close();
			return false;
		}

		//Move to next tile spot
		x += Tile::TILE_WIDTH;

		//If we've gone too far
		if (x >= screen_width*number_of_scenes) {
			//Move back
			x = 0;

			//Move to the next row
			y += Tile::TILE_HEIGHT;
		}
	}

	//Close the file
	map.close();

	//If the map was loaded fine
	return true;
}

void TileMap::show(SDL_Surface *screen,Camera *camera) {
	for (int t = 0; t < number_of_tiles; t++) {
		if (Utils::check_collision(camera->getCamera(), tiles[t]->getBox())
				== true) {
			//Show the tile
			if(tiles[t]->getType() == Tile::TILE_BACKGROUND){
				SDL_Rect rect;
				rect.x = tiles[t]->getBox().x % screen_width;
				rect.y = tiles[t]->getBox().y;
				rect.w = Tile::TILE_WIDTH;
				rect.h = Tile::TILE_HEIGHT;
				Utils::apply_surface(tiles[t]->getBox().x - camera->getCamera().x,
									tiles[t]->getBox().y - camera->getCamera().y, background,
									screen, &rect);

			}
			else{
			Utils::apply_surface(tiles[t]->getBox().x - camera->getCamera().x,
					tiles[t]->getBox().y - camera->getCamera().y, tileSheet,
					screen, &clipT[tiles[t]->getType()]);
			}
		}
	}
}

bool TileMap::touches_wall(SDL_Rect box) {
	//Go through the tiles
	for (int t = 0; t < number_of_tiles; t++) {
		//If the tile is a wall type tile
		if ((tiles[t]->getType() >= Tile::TILE_CENTER)
				&& (tiles[t]->getType() <= Tile::TILE_TOPLEFT)) {
			//If the collision box touches the wall tile
			if (Utils::check_collision(box, tiles[t]->getBox()) == true) {
				return true;
			}
		}
	}

	//If no wall tiles were touched
	return false;
}

int TileMap::getNumberOfScenes(){
	return number_of_scenes;
}

TileMap::~TileMap() {
	SDL_FreeSurface(tileSheet);
}

