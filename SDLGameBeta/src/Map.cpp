/*
 * Map.cpp
 *
 *  Created on: 30/01/2013
 *      Author: isac
 */

#include "Map.h"

Map::Map(string filename) {
	char * xml = (char*) Utils::loadFile(filename.c_str(), true);
	this->tmxMap = NLLoadTmxMap(xml);
	for (unsigned int i = 0; i < tmxMap->tilesets.size(); i++) {
		tmxMap->tilesets[i]->surface = Utils::load_image(
				tmxMap->tilesets[i]->filename);
	}

}

void Map::show(SDL_Surface *screen, Camera *camera) {

	for (unsigned int l = 0; l < tmxMap->layers.size(); l++) {
		//int initial_index = floor(( tmxMap->layers[l]->width*camera->getX() ) / tmxMap->width);
		//int final_index = ceil(( tmxMap->layers[l]->width* ( camera->getX() + camera->getW() ) ) / tmxMap->width);

		//for (int i = initial_index; i < final_index; i++) {
		for (int i = 0; i < tmxMap->layers[l]->width; i++) {
			for (int j = 0; j < tmxMap->layers[l]->height; j++) {

				int index = j * tmxMap->layers[l]->width + i;

				int source_tileset = getTilesetId(tmxMap->layers[l]->data[index]);

				if (source_tileset != -1) {
					SDL_Rect rect_tileset = getLocalRect(
						tmxMap->layers[l]->data[index], source_tileset);

					//rect screen é a posição que o tile vai ser colado na tela
					// este é o rect que deve ser checado por colisão com a câmera
					SDL_Rect rect_screen;
					rect_screen = getGlobalRect(i,j,source_tileset);
					if (camera->checkCollision(rect_screen) == true) {

						Utils::apply_surface(rect_screen.x - camera->getBox().x,
								rect_screen.y - camera->getBox().y,
								tmxMap->tilesets[source_tileset]->surface, screen,
								&rect_tileset);
					}
				} else {
					if (tmxMap->layers[l]->data[i] != 0)
						cerr << "invalid id in the map! layer:" << l << " data:"
								<< i << " value:" << tmxMap->layers[l]->data[i]
								<< endl;
				}
			}
		}
	}

}

int Map::getTilesetId(int gid) {
	uint k = 0;
	int target_tileset = -1;

	int num_tiles_width = tmxMap->tilesets[k]->width
			/ tmxMap->tilesets[k]->tileWidth;
	int num_tiles_height = tmxMap->tilesets[k]->height
			/ tmxMap->tilesets[k]->tileHeight;

	while (k < tmxMap->tilesets.size()) {
		if (gid >= tmxMap->tilesets[k]->firstGid
				&& gid
						<= ((num_tiles_width * num_tiles_height)
								+ tmxMap->tilesets[k]->firstGid)) {
			target_tileset = k;
			break;
		}
		k++;
	}
	return target_tileset;

}

SDL_Rect Map::getLocalRect(int gid, int tilesetId) {
	//k--;
	int local_id = gid - tmxMap->tilesets[tilesetId]->firstGid;
	int num_tiles_width = tmxMap->tilesets[tilesetId]->width
			/ tmxMap->tilesets[tilesetId]->tileWidth;

	SDL_Rect rect_tileset;

	// rect_tileset é a posição do tile no tileset
	//
	rect_tileset.x = (local_id % num_tiles_width)
			* tmxMap->tilesets[tilesetId]->tileWidth;
	rect_tileset.y = (local_id / num_tiles_width)
			* tmxMap->tilesets[tilesetId]->tileHeight;
	rect_tileset.w = tmxMap->tilesets[tilesetId]->tileWidth;
	rect_tileset.h = tmxMap->tilesets[tilesetId]->tileHeight;

	return rect_tileset;
}

SDL_Rect Map::getGlobalRect(int i,int j,int tilesetId){
	SDL_Rect rect_screen;
	rect_screen.x = i * tmxMap->tilesets[tilesetId]->tileWidth;
	rect_screen.y = j * tmxMap->tilesets[tilesetId]->tileHeight;
	rect_screen.w = tmxMap->tilesets[tilesetId]->tileWidth;
	rect_screen.h = tmxMap->tilesets[tilesetId]->tileHeight;
	return rect_screen;

}

NLTmxMap *Map::getMap() {
	return tmxMap;
}

NLTmxMapLayer * Map::getCollisionLayer() {
	if (tmxMap->layers.size() > 1)
		return tmxMap->layers[1];
	else
		return NULL;
}

Map::~Map() {
}

