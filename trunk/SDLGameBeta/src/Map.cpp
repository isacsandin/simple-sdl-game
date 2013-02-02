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
		tilesets[tmxMap->tilesets[i]] = Utils::load_image(
				tmxMap->tilesets[i]->filename);
	}

}

void Map::show(SDL_Surface *screen, Camera *camera) {

	for (unsigned int l = 0; l < tmxMap->layers.size(); l++) {
		for (int i = 0; i < tmxMap->layers[l]->height; i++) {
			for (int j = 0; j < tmxMap->layers[l]->width; j++) {

				int index = i * tmxMap->layers[l]->width + j;

				auto k = tilesets.begin();

				int num_tiles_width = k->first->width / k->first->tileWidth;
				int num_tiles_height = k->first->height / k->first->tileHeight;


				while (k != tilesets.end()) {
					if (tmxMap->layers[l]->data[index] >= k->first->firstGid
						&& tmxMap->layers[l]->data[index] <= ((num_tiles_width * num_tiles_height)+k->first->firstGid)) break;
					k++;
				}

				if (k != tilesets.end()) {
					//k--;
					int local_id = tmxMap->layers[l]->data[index] - k->first->firstGid;
					int num_tiles_width = k->first->width / k->first->tileWidth;

					SDL_Rect rect_tileset,rect_screen;

					// rect_tileset é a posição do tile no tileset
					rect_tileset.x = (local_id % num_tiles_width) * k->first->tileWidth;
					rect_tileset.y = (local_id / num_tiles_width) * k->first->tileHeight;
					rect_tileset.w = k->first->tileWidth;
					rect_tileset.h = k->first->tileHeight;

					//rect screen é a posição que o tile vai ser colado na tela
					// este é o rect que deve ser checado por colisão com a câmera
					rect_screen.x = j * k->first->tileWidth;
					rect_screen.y = i * k->first->tileHeight;
					rect_screen.w = k->first->tileWidth;
					rect_screen.h = k->first->tileHeight;
					if (Utils::check_collision(camera->getCamera(), rect_screen) == true) {

						Utils::apply_surface(rect_screen.x - camera->getCamera().x,
								rect_screen.y - camera->getCamera().y, k->second, screen,
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

Map::~Map() {
}

