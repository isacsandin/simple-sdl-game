/*
 * Background.cpp
 *
 *  Created on: 27/01/2013
 *      Author: isac
 */

#include "Background.h"

Background::Background() {
	background = NULL;
	background = Utils::load_image("resources/background.png");
	bgX = 0, bgY = 0;
}

void Background::show(SDL_Surface *screen) {
	//Scroll background
	bgX -= 2;

	//If the background has gone too far
	if (bgX <= -background->w) {
		//Reset the offset
		bgX = 0;
	}

	Utils::apply_surface(bgX,bgY, background, screen);
	Utils::apply_surface(bgX + background->w,bgY, background, screen);
}

Background::~Background() {
	SDL_FreeSurface(background);
}
