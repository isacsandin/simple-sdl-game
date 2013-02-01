/*
 * Map.h
 *
 *  Created on: 30/01/2013
 *      Author: isac
 */

#ifndef MAP_H_
#define MAP_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <map>
#include "NLTmxMap.h"
#include "Utils.h"
#include "Camera.h"

class Map {
private:
	NLTmxMap* tmxMap;
	map<NLTmxMapTileset *,SDL_Surface *> tilesets;
public:
	Map(string filename);
	virtual ~Map();
	void show(SDL_Surface *screen,Camera *camera);
};

#endif /* MAP_H_ */
