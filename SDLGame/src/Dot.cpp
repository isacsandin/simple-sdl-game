///*
// * Dot.cpp
// *
// *  Created on: 26/01/2013
// *      Author: isac
// */
//
//#include "Dot.h"
//
//Dot::Dot(int screen_width, int screen_height) {
//
//	SCREEN_WIDTH = screen_width;
//	SCREEN_HEIGHT = screen_height;
//
//	dot_l = NULL;
//	dot_r = NULL;
//
//	load_files();
//
//	//Initialize the offsets
//	x = 0;
//	y = 360;
//
//	//Initialize the velocity
//	xVel = 50;
//	yVel = 50;
//
//	moving = -1;
//	down = false;
//	up = false;
//	up_s = false;
//	jump = false;
//	jump_alt = 0;
//	jump_done = false;
//	jump_started = false;
//
//	shot_s = false;
//	shot_ready = false;
//	shot_started = false;
//	shoted = false;
//
//	death_s = false;
//	death_started = false;
//
//	//Moving
//	animations[0] = 0;
//	clip[0].x = 0;
//	clip[0].y = 0;
//	clip[0].w = 68;
//	clip[0].h = 73;
//
//	clip[1].x = 72;
//	clip[1].y = 0;
//	clip[1].w = 68;
//	clip[1].h = 73;
//
//	clip[2].x = 144;
//	clip[2].y = 0;
//	clip[2].w = 68;
//	clip[2].h = 73;
//
//	clip[3].x = 216;
//	clip[3].y = 0;
//	clip[3].w = 68;
//	clip[3].h = 73;
//
//	clip[4].x = 288;
//	clip[4].y = 0;
//	clip[4].w = 68;
//	clip[4].h = 73;
//
//	clip[5].x = 360;
//	clip[5].y = 0;
//	clip[5].w = 68;
//	clip[5].h = 73;
//
//	//Stationary
//	animations[1] = 6;
//	clip[6].x = 0;
//	clip[6].y = 80;
//	clip[6].w = 68;
//	clip[6].h = 73;
//
//	//Crouched
//	animations[2] = 7;
//	clip[7].x = 360;
//	clip[7].y = 160;
//	clip[7].w = 68;
//	clip[7].h = 73;
//
//	//Jumping
//	animations[3] = 8;
//	clip[8].x = 72;
//	clip[8].y = 80;
//	clip[8].w = 68;
//	clip[8].h = 73;
//
//	clip[9].x = 144;
//	clip[9].y = 80;
//	clip[9].w = 68;
//	clip[9].h = 73;
//
//	clip[10].x = 216;
//	clip[10].y = 80;
//	clip[10].w = 68;
//	clip[10].h = 73;
//
//	clip[11].x = 288;
//	clip[11].y = 80;
//	clip[11].w = 68;
//	clip[11].h = 73;
//
//	clip[12].x = 72;
//	clip[12].y = 80;
//	clip[12].w = 68;
//	clip[12].h = 73;
//
//	//Shooting
//	animations[4] = 13;
//	clip[13].x = 144;
//	clip[13].y = 160;
//	clip[13].w = 68;
//	clip[13].h = 73;
//
//	clip[14].x = 216;
//	clip[14].y = 160;
//	clip[14].w = 68;
//	clip[14].h = 73;
//
//	clip[15].x = 288;
//	clip[15].y = 160;
//	clip[15].w = 68;
//	clip[15].h = 73;
//
//	//Dying
//	animations[5] = 16;
//	clip[16].x = 288;
//	clip[16].y = 240;
//	clip[16].w = 68;
//	clip[16].h = 73;
//
//	clip[17].x = 216;
//	clip[17].y = 240;
//	clip[17].w = 68;
//	clip[17].h = 73;
//
//	clip[18].x = 144;
//	clip[18].y = 240;
//	clip[18].w = 68;
//	clip[18].h = 73;
//
//	clip[19].x = 72;
//	clip[19].y = 240;
//	clip[19].w = 68;
//	clip[19].h = 73;
//
//	clip[20].x = 0;
//	clip[20].y = 240;
//	clip[20].w = 68;
//	clip[20].h = 73;
//
//	//Climbing
//	animations[6] = 21;
//	clip[21].x = 0;
//	clip[21].y = 0;
//	clip[21].w = 68;
//	clip[21].h = 73;
//
//	clip[22].x = 72;
//	clip[22].y = 0;
//	clip[22].w = 68;
//	clip[22].h = 73;
//
//	clip[23].x = 144;
//	clip[23].y = 0;
//	clip[23].w = 68;
//	clip[23].h = 73;
//
//	clip[24].x = 216;
//	clip[24].y = 0;
//	clip[24].w = 68;
//	clip[24].h = 73;
//
//	clip[25].x = 288;
//	clip[25].y = 0;
//	clip[25].w = 68;
//	clip[25].h = 73;
//
//	clip[26].x = 360;
//	clip[26].y = 0;
//	clip[26].w = 68;
//	clip[26].h = 73;
//
//	//Falling
//	animations[7] = 27;
//	clip[27].x = 0;
//	clip[27].y = 0;
//	clip[27].w = 68;
//	clip[27].h = 73;
//
//	clip[28].x = 72;
//	clip[28].y = 0;
//	clip[28].w = 68;
//	clip[28].h = 73;
//
//	clip[29].x = 144;
//	clip[29].y = 0;
//	clip[29].w = 68;
//	clip[29].h = 73;
//
//	clip[30].x = 216;
//	clip[30].y = 0;
//	clip[30].w = 68;
//	clip[30].h = 73;
//
//	clip[31].x = 288;
//	clip[31].y = 0;
//	clip[31].w = 68;
//	clip[31].h = 73;
//
//	clip[32].x = 360;
//	clip[32].y = 0;
//	clip[32].w = 68;
//	clip[32].h = 73;
//	animations[8] = 33;
//
//}
//
//Dot::~Dot() {
//	//Free the surface
//	SDL_FreeSurface(dot_l);
//	SDL_FreeSurface(dot_r);
//}
//
//void Dot::handle_input(SDL_Event event) {
//	if (event.type == SDL_KEYDOWN) {
//		switch (event.key.keysym.sym) {
//		case SDLK_SPACE:
//			up = true;
//			break;
//		case SDLK_UP:
//			up_s = true;
//			break;
//		case SDLK_DOWN:
//			down = true;
//			break;
//		case SDLK_LEFT:
//			moving = 2;
//			break;
//		case SDLK_RIGHT:
//			moving = 1;
//			break;
//		case SDLK_p:
//			climbing_s = true;
//			break;
//		default:
//			break;
//
//		}
//	} else {
//		if (event.type == SDL_KEYUP) {
//			switch (event.key.keysym.sym) {
//			case SDLK_UP:
//				climbing_s = false;
//				up_s = false;
//				break;
//			case SDLK_DOWN:
//				down = false;
//				climbing_s = false;
//				break;
//			case SDLK_LEFT:
//				moving = -2;
//				break;
//			case SDLK_RIGHT:
//				moving = -1;
//				break;
//			case SDLK_t:
//				shot_s = true;
//				break;
//			case SDLK_m:
//				death_s = true;
//				break;
//			case SDLK_o:
//				climbing_s = false;
//				break;
//			default:
//				break;
//			}
//		}
//	}
//
//}
//
//void Dot::move(Uint32 deltaTicks) {
//	/* Moving to the left or right */
//	if (moving > 0 && !down && !up) {
//
//		if (sprite_frame >= animations[1])
//			sprite_frame = animations[0];
//		sprite_frame += 1;
//		if (sprite_frame >= animations[1])
//			sprite_frame = animations[0];
//
//		if (moving == 1)
//			//Move the dot right
//			x += xVel * (deltaTicks / 1000.f);
//		else
//			//Move the dot left
//			x -= xVel * (deltaTicks / 1000.f);
//
//		//If the dot went too far to the left
//		if (x < 0) {
//			//Move back
//			x = 0;
//		}
//		//or the right
//		else if (x + DOT_WIDTH > SCREEN_WIDTH) {
//			//Move back
//			x = SCREEN_WIDTH - DOT_WIDTH;
//		}
//
//	}
//	/* Climbing or Crouched */
//	else {
//
//		if (down && !up) {
//
//			if (climbing_s) {
//				/* Climbing DOWN*/
//				y += yVel * (deltaTicks / 1000.f);
//				if (sprite_frame < animations[6]
//						|| sprite_frame >= animations[7])
//					sprite_frame = animations[6];
//				sprite_frame += 1;
//				if (sprite_frame < animations[6]
//						|| sprite_frame >= animations[7])
//					sprite_frame = animations[6];
//			} else {
//				/* Crouched */
//				sprite_frame = animations[2];
//			}
//		} else {
//			if (up) {
//				/* JUMP */
//				if (jump_alt <= ((animations[4] - animations[3]) - 1)
//						&& !jump_done) {
//					y -= yVel * (deltaTicks / 1000.f);
//					jump_alt += 1;
//
//					if (!jump_started) {
//						sprite_frame = animations[3];
//						jump_started = true;
//					} else
//						sprite_frame += 1;
//				} else {
//					jump_done = true;
//					y += yVel * (deltaTicks / 1000.f);
//					jump_alt -= 1;
//					sprite_frame -= 1;
//
//					if (jump_alt == 0) {
//						up = false;
//						jump_done = false;
//						jump_started = false;
//						sprite_frame = animations[1];
//					}
//				}
//
//				if (moving == -1 || moving == 1)
//					x += xVel * (deltaTicks / 1000.f);
//				else if (moving == -2 || moving == 2)
//					x -= xVel * (deltaTicks / 1000.f);
//
//				if (y < 0) {
//					//Move back
//					y = 0;
//				}
//				//or down
//				else if (y + DOT_HEIGHT > SCREEN_HEIGHT) {
//					//Move back
//					y = SCREEN_HEIGHT - DOT_HEIGHT;
//				}
//
//			} else {
//				/* Climbing UP */
//				if (climbing_s && up_s) {
//					y -= yVel * (deltaTicks / 1000.f);
//					if (sprite_frame < animations[6]
//							|| sprite_frame >= animations[7])
//						sprite_frame = animations[6];
//					sprite_frame += 1;
//					if (sprite_frame < animations[6]
//							|| sprite_frame >= animations[7])
//						sprite_frame = animations[6];
//				} else {
//
//					if (!death())
//						if (!shot())
//							sprite_frame = animations[1];
//				}
//			}
//		}
//	}
//}
//
//int Dot::shot() {
//	if (shot_s) {
//		if (!shot_started) {
//			sprite_frame = animations[4];
//			shot_started = true;
//		}
//
//		if (sprite_frame == animations[5] - 1) {
//			shoted = false;
//			shot_s = false;
//			shot_ready = false;
//			shot_started = false;
//			sprite_frame = animations[1];
//		} else
//		sprite_frame += 1;
//	} else
//	return 0;
//
//	return 1;
//}
//
//int Dot::death() {
//	if (death_s) {
//		if (!death_started) {
//			sprite_frame = animations[5];
//			death_started = true;
//		}
//
//		if (sprite_frame == animations[6] - 1) {
//			death_s = false;
//			death_started = false;
//			sprite_frame = animations[1];
//		} else
//		sprite_frame += 1;
//	} else
//	return 0;
//
//	return 1;
//
//}
//
//void Dot::show(SDL_Surface *screen) {
//	if (moving == 2 || moving == -2) {
//		SDL_SetAlpha(dot_l, 0, dot_l->format->alpha);
//		Utils::apply_surface((int) x, (int) y, dot_l, screen,
//				&clip[sprite_frame]);
//	} else if (moving == 1 || moving == -1) {
//		SDL_SetAlpha(dot_r, 0, dot_r->format->alpha);
//		Utils::apply_surface((int) x, (int) y, dot_r, screen,
//				&clip[sprite_frame]);
//	}
//
//}
//
//bool Dot::load_files() {
//	//Load the dot image
//	dot_l = Utils::load_image("resources/sprite_l.png");
//	dot_r = Utils::load_image("resources/sprite_r.png");
//
//	//If everything loaded fine
//	return true;
//}


/*
 * Dot.cpp
 *
 *  Created on: 26/01/2013
 *      Author: isac
 */

#include "Dot.h"

Dot::Dot(int screen_width, int screen_height) {

	SCREEN_WIDTH = screen_width;
	SCREEN_HEIGHT = screen_height;

	dot_l = NULL;
	dot_r = NULL;
	load_files();

	//Initialize the offsets
	x = 0;
	y = 360;

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
	climbing_s=false;

	shot_s = false;
	shot_ready = false;
	shot_started = false;
	shoted = false;

	death_s = false;
	death_started = false;


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
	clip[3].h = default_h-25;

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

Dot::~Dot() {
	//Free the surface
	SDL_FreeSurface(dot_l);
	SDL_FreeSurface(dot_r);
}

void Dot::handle_input(SDL_Event event) {
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
				death_s = true;
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

void Dot::move(Uint32 deltaTicks) {
	/* Moving to the left or right */
	if (moving > 0 && !down && !up) {

		if (sprite_frame >= animations[1])
			sprite_frame = animations[0];
		sprite_frame += 1;
		if (sprite_frame >= animations[1])
			sprite_frame = animations[0];

		if (moving == 1)
			//Move the dot right
			x += xVel * (deltaTicks / 1000.f);
		else
			//Move the dot left
			x -= xVel * (deltaTicks / 1000.f);

		//If the dot went too far to the left
		if (x < 0) {
			//Move back
			x = 0;
		}
		//or the right
		else if (x + DOT_WIDTH > SCREEN_WIDTH) {
			//Move back
			x = SCREEN_WIDTH - DOT_WIDTH;
		}

	}
	/* Climbing or Crouched */
	else {

		if (down && !up) {

			if (climbing_s) {
				/* Climbing DOWN*/
				y += yVel * (deltaTicks / 1000.f);
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
//				y += yVel * (deltaTicks / 1000.f);
			}
		} else {
			if (up) {
				/* JUMP */
				if (jump_alt <= ((animations[4] - animations[3]) - 1)
						&& !jump_done) {
					y -= yVel * (deltaTicks / 1000.f);
					jump_alt += 1;

					if (!jump_started) {
						sprite_frame = animations[3];
						jump_started = true;
					} else
						sprite_frame += 1;
				} else {
					jump_done = true;
					y += yVel * (deltaTicks / 1000.f);
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
					x += xVel * (deltaTicks / 1000.f);
				else if (moving == -2 || moving == 2)
					x -= xVel * (deltaTicks / 1000.f);

				if (y < 0) {
					//Move back
					y = 0;
				}
				//or down
				else if (y + DOT_HEIGHT > SCREEN_HEIGHT) {
					//Move back
					y = SCREEN_HEIGHT - DOT_HEIGHT;
				}

			} else {
				/* Climbing UP */
				if (climbing_s && up_s) {
					y -= yVel * (deltaTicks / 1000.f);
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

int Dot::shot() {
	if (shot_s) {
		if (!shot_started) {
			sprite_frame = animations[4];
			shot_started = true;
		}
		else{
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

int Dot::death() {
	if (death_s) {
		if (!death_started) {
			sprite_frame = animations[5];
			death_started = true;
		}
		else{
		if (sprite_frame == animations[6] - 1) {
			death_s = false;
			death_started = false;
			sprite_frame = animations[1];
		} else
		sprite_frame += 1;
		}
	} else
	return 0;

	return 1;

}

void Dot::show(SDL_Surface *screen) {
	SDL_Rect offset;
	if (moving == 2 || moving == -2) {
		Utils::apply_surface((int) x, (int) y, dot_l, screen,
				&clip[sprite_frame]);
	} else if (moving == 1 || moving == -1) {
		Utils::apply_surface((int) x, (int) y, dot_r, screen,
				&clip[sprite_frame]);
	}

}

bool Dot::load_files() {
	//Load the dot image
	dot_r = Utils::load_image("resources/spriteMario_r.png");
	dot_l = Utils::load_image("resources/spriteMario_l.png");
	//If everything loaded fine
	return true;
}
