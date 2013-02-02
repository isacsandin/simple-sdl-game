/*
 * Sound.h
 *
 *  Created on: 29/01/2013
 *      Author: isac
 */

#ifndef SOUND_H_
#define SOUND_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include <fstream>
#include "Utils.h"

class Sound {
private:
	//The music that will be played
	Mix_Music *music;

public:
	Sound();
	virtual ~Sound();
	int handleInput(SDL_Event event);
	void playEffect(string filename);
};

#endif /* SOUND_H_ */
