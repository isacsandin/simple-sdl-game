/*
 * Stage.h
 *
 *  Created on: 03/02/2013
 *      Author: isac
 */

#ifndef STAGE_H_
#define STAGE_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include "Timer.h"
#include "Sound.h"
#include "Camera.h"
#include "Map.h"
#include "Mario.h"
#include "Koopa.h"
#include "Physics.h"
#include "CheckPointBlock.h"

class Stage {
private:
	Map *map;
	Mario *mario;
	Koopa *koopa;
	Timer *timer;
	Camera *camera;
	Sound *sound;
	Physics *physics;
	CheckPointBlock *begin, *end;
	SDL_Surface *screen;
	SDL_Event event;
	int screenWidth,screenHeight;
public:
	Stage(SDL_Surface *screen);
	void handleInput(SDL_Event event);
	virtual ~Stage();
	void loop();

	void setCheckpointBegin(CheckPointBlock* begin) {
		this->begin = begin;
	}

	void setCheckpointEnd(CheckPointBlock* end) {
		this->end = end;
	}


	void setCamera(Camera* camera) {
		this->camera = camera;
	}

	void setKoopa(Koopa* koopa) {
		this->koopa = koopa;
	}

	void setMap(Map* map) {
		this->map = map;
	}

	void setMario(Mario* mario) {
		this->mario = mario;
	}

	int getScreenWidth() const {
		return screenWidth;
	}

	int getScreenHeight() const {
		return screenHeight;
	}

	void setSound(Sound* sound) {
		this->sound = sound;
	}

	void setTimer(Timer* timer) {
		this->timer = timer;
	}
};

#endif /* STAGE_H_ */
