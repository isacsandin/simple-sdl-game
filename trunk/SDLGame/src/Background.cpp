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
	bgX = 0, bgY = 0,moving = 0;
}

void Background::handle_input(SDL_Event event)
{
	if( event.type == SDL_KEYDOWN )
	{
		switch( event.key.keysym.sym )
		{
			case SDLK_LEFT: moving = -1; break;
			case SDLK_RIGHT: moving = 1; break;
			default: break;

		}
	}
	else {
		if( event.type == SDL_KEYUP){
			switch( event.key.keysym.sym )
			{
				case SDLK_LEFT: moving = 0;  break;
				case SDLK_RIGHT: moving = 0; break;
				default: break;
			}
		}
	}

}

void Background::move(Uint32 deltaTicks){
	//Scroll background
	bgX -= (100*moving);

	//If the background has gone too far
	if (bgX <= -background->w) {
		//Reset the offset
		bgX = 0;
	}
	if (bgX > 0) {
		//Reset the offset
		bgX = -background->w;
	}
	cout << bgX << endl;
}

void Background::show(SDL_Surface *screen) {


	Utils::apply_surface(bgX,bgY, background, screen);
	Utils::apply_surface(bgX + background->w,bgY, background, screen);
}

Background::~Background() {
	SDL_FreeSurface(background);
}
