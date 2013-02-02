/*
 * Enemy.h
 *
 *  Created on: 02/02/2013
 *      Author: feliperviegas
 */

#ifndef KOOPA_H_
#define KOOPA_H_
#include <vector>
#include <SDL/SDL.h>
#include "Utils.h"
#include "Enemy.h"

class Koopa: public Enemy {

private:
	SDL_Surface *koopa_l, *koopa_r;
	SDL_Rect clip[3];
	float xVel;
	int moving;
	int spriteFrame;
public:
	Koopa();
	virtual ~Koopa();
	void move(Uint32 deltaTicks);
	void show(SDL_Surface *screen);
	bool checkCollision(SDL_Rect rect);
};

#endif /* ENEMY_H_ */
