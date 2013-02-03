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
		tmxMap->tilesets[i]->surface = Utils::load_image(tmxMap->tilesets[i]->filename);
	}

}

void Map::show(SDL_Surface *screen, Camera *camera) {

	for (unsigned int l = 0; l < tmxMap->layers.size(); l++) {
		for (int i = 0; i < tmxMap->layers[l]->height; i++) {

			//int initial_index = floor(( tmxMap->layers[l]->width*camera->getX() ) / tmxMap->width)-1;
			//int final_index = ceil(( tmxMap->layers[l]->width* ( camera->getX() + camera->getW() ) ) / tmxMap->width)+1;

			//for (int j = initial_index; j < final_index; j++) {

			for (int j = 0; j < tmxMap->layers[l]->width; j++) {

				int index = i * tmxMap->layers[l]->width + j;

				uint k = 0;
				int target_tileset = -1;

				int num_tiles_width = tmxMap->tilesets[k]->width / tmxMap->tilesets[k]->tileWidth;
				int num_tiles_height = tmxMap->tilesets[k]->height / tmxMap->tilesets[k]->tileHeight;

				while (k < tmxMap->tilesets.size()) {
					if (tmxMap->layers[l]->data[index] >= tmxMap->tilesets[k]->firstGid
							&& tmxMap->layers[l]->data[index]
									<= ((num_tiles_width * num_tiles_height)
											+ tmxMap->tilesets[k]->firstGid)){
						target_tileset = k;
						break;
					}
					k++;
				}

				if (target_tileset != -1) {
					//k--;
					int local_id = tmxMap->layers[l]->data[index]
							- tmxMap->tilesets[k]->firstGid;
					int num_tiles_width = tmxMap->tilesets[k]->width / tmxMap->tilesets[k]->tileWidth;

					SDL_Rect rect_tileset, rect_screen;

					// rect_tileset é a posição do tile no tileset
					//
					rect_tileset.x = (local_id % num_tiles_width)
							* tmxMap->tilesets[k]->tileWidth;
					rect_tileset.y = (local_id / num_tiles_width)
							* tmxMap->tilesets[k]->tileHeight;
					rect_tileset.w = tmxMap->tilesets[k]->tileWidth;
					rect_tileset.h = tmxMap->tilesets[k]->tileHeight;

					//rect screen é a posição que o tile vai ser colado na tela
					// este é o rect que deve ser checado por colisão com a câmera
					rect_screen.x = j * tmxMap->tilesets[k]->tileWidth;
					rect_screen.y = i * tmxMap->tilesets[k]->tileHeight;
					rect_screen.w = tmxMap->tilesets[k]->tileWidth;
					rect_screen.h = tmxMap->tilesets[k]->tileHeight;
					if (camera->checkCollision(rect_screen) == true) {

						Utils::apply_surface(rect_screen.x - camera->getBox().x,
								rect_screen.y - camera->getBox().y, tmxMap->tilesets[k]->surface,
								screen, &rect_tileset);
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

NLTmxMapLayer * Map::getCollisionLayer() {
	if (tmxMap->layers.size() > 1)
		return tmxMap->layers[1];
	else
		return NULL;
}

Map::~Map() {
}

