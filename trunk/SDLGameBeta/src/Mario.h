/*
 * Mario.h
 *
 *  Created on: 02/02/2013
 *      Author: guineri
 */

#ifndef MARIO_H_
#define MARIO_H_

#include "Hero.h"
#include "Utils.h"

class Mario: public Hero {
public:
	Mario();
	virtual ~Mario();
	void handleInput(SDL_Event event);
	void move(Uint32 deltaTicks);
	int shot();
	void death();
	void show(SDL_Surface *screen);
	bool checkCollision(SDL_Rect rect);
	void setXVel(int xVel);
	int life;

private:
	 //The velocity of the dot
	    float xVel, yVel;

		int moving;

		bool down;
		bool crouched;
		bool climbing_s,climbing_started;

		bool up,up_s;
		bool jump,jump_done,jump_started;
		int jump_alt;

		bool shot_s,shot_ready,shot_started,shoted;

		bool death_s,death_started;

		//The portions of the sprite map to be blitted
		SDL_Rect clip[ 70 ];

		int animations[10]; 	// 0 - Moving
								// 1 - Stationary
								// 2 - Crouched
								// 3 - Jump
								// 4 - Shooting
								// 5 - Dying
								// 6 - Climbing
								// 7 - Falling

		int sprite_frame;

		//The attributes of the dot
		const static int DOT_WIDTH = 20;
		const static int DOT_HEIGHT = 20;
		const static int DOT_VEL = 5;

		SDL_Surface *mario_l, *mario_r;

};

#endif /* MARIO_H_ */
