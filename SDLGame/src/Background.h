/*
 * Background.h
 *
 *  Created on: 27/01/2013
 *      Author: isac
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include "Utils.h"

class Background {
public:
	Background();
	virtual ~Background();
	void show(SDL_Surface *screen);

private:
	SDL_Surface *background;
    int bgX, bgY;

};

#endif /* BACKGROUND_H_ */
