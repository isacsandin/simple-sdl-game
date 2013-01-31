/*
 * Map.cpp
 *
 *  Created on: 30/01/2013
 *      Author: isac
 */

#include "Map.h"

Map::Map() {
	char * xml = (char*) Utils::loadFile("resources/background.tmx", true);
	this->tmxMap = NLLoadTmxMap(xml);
	for (int i = 0; i < tmxMap->tilesets.size(); i++) {
		tilesets[tmxMap->tilesets[i]] = Utils::load_image(
				tmxMap->tilesets[i]->filename);
	}
/*	cout << tmxMap->layers[0]->width << " " << tmxMap->layers[0]->height;
	cin.get();
	for (int l = 0; l < tmxMap->layers.size(); l++) {
			for (int i = 0; i < tmxMap->layers[l]->height; i++) {
				for (int j = 0; j < tmxMap->layers[l]->width; j++) {
					int index = i * tmxMap->layers[l]->width + j;
					cout << tmxMap->layers[l]->data[index] << ",";
				}
				cout << endl;
			}
	}
	cin.get();*/

}

void Map::show(SDL_Surface *screen, Camera *camera) {

	for (int l = 0; l < tmxMap->layers.size(); l++) {
		for (int i = 0; i < tmxMap->layers[l]->height; i++) {
			for (int j = 0; j < tmxMap->layers[l]->width; j++) {

				int index = i * tmxMap->layers[l]->width + j;

				auto k = tilesets.begin();

				while (k != tilesets.end()
						&& !(tmxMap->layers[l]->data[index] >= k->first->firstGid
						&& tmxMap->layers[l]->data[index]
						<= ((k->first->width / k->first->tileWidth)
						* (k->first->height / k->first->tileHeight)))) {
					k++;
				}

				if (k != tilesets.end()) {
					//k--;
					int local_id = tmxMap->layers[l]->data[index] - k->first->firstGid;
					SDL_Rect rect;
					int num_tiles_width = k->first->width / k->first->tileWidth;
					int num_tiles_height = k->first->height / k->first->tileHeight;
					rect.x = (local_id % num_tiles_width) * k->first->tileWidth;
					rect.y = (local_id / num_tiles_width) * k->first->tileHeight;
					rect.w = k->first->tileWidth;
					rect.h = k->first->tileHeight;
					//cout << local_id << " " << rect.x << " " << rect.y  << endl;
					//cin.get();
					if (Utils::check_collision(camera->getCamera(), rect) == true) {
						int x = j * k->first->tileWidth;
						int y = i * k->first->tileHeight;
						//cout << x << " " << y << endl;
						//cin.get();
						Utils::apply_surface(x - camera->getCamera().x,
								y - camera->getCamera().y, k->second, screen,
								&rect);


					}
				} else {
					cerr << "invalid id in the map! layer:" << l << " data:"
							<< i << " value:" << tmxMap->layers[l]->data[i]
							<< endl;
					return;
				}
			}
		}
	}

}

Map::~Map() {
// TODO Auto-generated destructor stub
}

