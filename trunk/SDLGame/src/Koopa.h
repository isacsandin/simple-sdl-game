/*
 * Enemy.h
 *
 *  Created on: 02/02/2013
 *      Author: feliperviegas
 */

#ifndef ENEMY_H_
#define ENEMY_H_
#include "Utils.h"
#include <vector>
#include <SDL/SDL.h>
#include "Utils.h"

class Koopa {

private:
	SDL_Surface *koopa_l, *koopa_r;
	SDL_Rect clip[3];
	float x, y;
	float xVel;
	int moving;
	int spriteFrame;
public:
	Koopa();
	virtual ~Koopa();
	void move(Uint32 deltaTicks);
	void show(SDL_Surface *screen);
};

#endif /* ENEMY_H_ */
