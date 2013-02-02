/*
 * Mario.cpp
 *
 *  Created on: 02/02/2013
 *      Author: guineri
 */

#include "Mario.h"

Mario::Mario() {

	// TODO Auto-generated constructor stub
	mario_r = Utils::load_image("resources/spriteMario_r.png");
	mario_l = Utils::load_image("resources/spriteMario_l.png");

	//Initialize the velocity
	xVel = 50;
	yVel = 150;

	moving = -1;
	down = false;
	up = false;
	up_s = false;
	jump = false;
	jump_alt = 0;
	jump_done = false;
	jump_started = false;
	climbing_s = false;
	climbing_started = false;

	shot_s = false;
	shot_ready = false;
	shot_started = false;
	shoted = false;

	death_s = false;
	death_started = false;

	crouched = false;
	sprite_frame = animations[1];

	int default_w = 40, default_h = 60;
	//  x_inicial = 15
	//  y_inicial = 75
	//	offset_x = 80
	//	offset_y = 75
	//Moving
	animations[0] = 0;
	clip[0].x = 20;
	clip[0].y = 150;
	clip[0].w = default_w;
	clip[0].h = default_h;

	clip[1].x = 90;
	clip[1].y = 150;
	clip[1].w = default_w;
	clip[1].h = default_h;

	//Stationary
	animations[1] = 2;
	clip[2].x = 340;
	clip[2].y = 150;
	clip[2].w = default_w;
	clip[2].h = default_h;

	//Crouched
	animations[2] = 3;
	clip[3].x = 165;
	clip[3].y = 240;
	clip[3].w = default_w + 5;
	clip[3].h = default_h - 25;

	//Jumping
	animations[3] = 4;
	clip[4].x = 340;
	clip[4].y = 225;
	clip[4].w = default_w;
	clip[4].h = default_h;

	clip[5].x = 260;
	clip[5].y = 225;
	clip[5].w = default_w;
	clip[5].h = default_h + 5;

	//Shooting
	animations[4] = 6;
	clip[6].x = 160;
	clip[6].y = 150;
	clip[6].w = default_w;
	clip[6].h = default_h;

	clip[7].x = 250;
	clip[7].y = 150;
	clip[7].w = default_w;
	clip[7].h = default_h;

	//Dying
	animations[5] = 8;
	clip[8].x = 15;
	clip[8].y = 70;
	clip[8].w = default_w;
	clip[8].h = default_h;

	//Climbing
	animations[6] = 9;
	clip[9].x = 280;
	clip[9].y = 1430;
	clip[9].w = default_w + 5;
	clip[9].h = default_h;

	clip[10].x = 220;
	clip[10].y = 1430;
	clip[10].w = default_w + 5;
	clip[10].h = default_h;

	animations[7] = 11;

}

Mario::~Mario() {
	// TODO Auto-generated destructor stub
}

void Mario::handleInput(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
		case SDLK_SPACE:
			up = true;
			break;
		case SDLK_UP:
			up_s = true;
			break;
		case SDLK_DOWN:
			down = true;
			break;
		case SDLK_LEFT:
			moving = 2;
			break;
		case SDLK_RIGHT:
			moving = 1;
			break;
		case SDLK_p:
			climbing_s = true;
			break;
		case SDLK_m:
			death_s = true;
			break;
		default:
			break;

		}
	} else {
		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				climbing_s = false;
				up_s = false;
				break;
			case SDLK_DOWN:
				down = false;
				climbing_s = false;
				break;
			case SDLK_LEFT:
				moving = -2;
				break;
			case SDLK_RIGHT:
				moving = -1;
				break;
			case SDLK_t:
				shot_s = true;
				break;
			case SDLK_m:
				death_s = false;
				break;
			case SDLK_o:
				climbing_s = false;
				break;
			default:
				break;
			}
		}
	}

}

void Mario::move(Uint32 deltaTicks) {
	/* Moving to the left or right */
	if (moving > 0 && !down && !up) {

		if (sprite_frame >= animations[1])
			sprite_frame = animations[0];
		sprite_frame += 1;
		if (sprite_frame >= animations[1])
			sprite_frame = animations[0];

		if (moving == 1)
			//Move the dot right
			this->getBox().x += xVel * (deltaTicks / 1000.f);
		else
			//Move the dot left
			this->getBox().x -= xVel * (deltaTicks / 1000.f);

	}
	/* Climbing or Crouched */
	else {

		if (down && !up) {

			if (climbing_s) {
				/* Climbing DOWN*/
				this->getBox().y += yVel * (deltaTicks / 1000.f);
				if (sprite_frame < animations[6]
						|| sprite_frame >= animations[7])
					sprite_frame = animations[6];
				sprite_frame += 1;
				if (sprite_frame < animations[6]
						|| sprite_frame >= animations[7])
					sprite_frame = animations[6];
			} else {
				/* Crouched */
				sprite_frame = animations[2];
				this->getBox().y += yVel * (deltaTicks / 1000.f);
			}
		} else {
			if (up) {
				/* JUMP */
				if (jump_alt <= ((animations[4] - animations[3]) - 1)
						&& !jump_done) {
					this->getBox().y -= yVel * (deltaTicks / 1000.f);
					jump_alt += 1;

					if (!jump_started) {
						sprite_frame = animations[3];
						jump_started = true;
					} else
						sprite_frame += 1;
				} else {
					jump_done = true;
					this->getBox().y += yVel * (deltaTicks / 1000.f);
					jump_alt -= 1;
					sprite_frame -= 1;

					if (jump_alt == 0) {
						up = false;
						jump_done = false;
						jump_started = false;
						sprite_frame = animations[1];
					}
				}

				if (moving == -1 || moving == 1)
					this->getBox().x += xVel * (deltaTicks / 1000.f);
				else if (moving == -2 || moving == 2)
					this->getBox().x -= xVel * (deltaTicks / 1000.f);

			} else {
				/* Climbing UP */
				if (climbing_s && up_s) {
					this->getBox().y -= yVel * (deltaTicks / 1000.f);
					if (sprite_frame < animations[6]
							|| sprite_frame >= animations[7])
						sprite_frame = animations[6];
					sprite_frame += 1;
					if (sprite_frame < animations[6]
							|| sprite_frame >= animations[7])
						sprite_frame = animations[6];
				} else {

					if (!death())
						if (!shot())
							sprite_frame = animations[1];
				}
			}
		}
	}
}

int Mario::shot() {
	if (shot_s) {
		if (!shot_started) {
			sprite_frame = animations[4];
			shot_started = true;
		} else {
			if (sprite_frame == animations[5] - 1) {
				shoted = false;
				shot_s = false;
				shot_ready = false;
				shot_started = false;
				sprite_frame = animations[1];
			} else
				sprite_frame += 1;
		}
	} else
		return 0;

	return 1;
}

int Mario::death() {
	if (death_s) {
		if (!death_started) {
			sprite_frame = animations[5];
			death_started = true;
		} else {
			if (sprite_frame == animations[6] - 1) {
				//death_s = false;
				death_started = false;
				//sprite_frame = animations[1];
			} else
				sprite_frame += 1;
		}
	} else
		return 0;

	return 1;

}

void Mario::show(SDL_Surface *screen) {
	SDL_Rect offset;
	if (moving == 2 || moving == -2) {
		Utils::apply_surface((int) this->getBox().x, (int) this->getBox().y,
				mario_l, screen, &clip[sprite_frame]);
	} else if (moving == 1 || moving == -1) {
		Utils::apply_surface((int) this->getBox().x, (int) this->getBox().y,
				mario_r, screen, &clip[sprite_frame]);
	}

}
