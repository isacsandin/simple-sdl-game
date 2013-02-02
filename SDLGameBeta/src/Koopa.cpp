/*
 * Enemy.cpp
 *
 *  Created on: 02/02/2013
 *      Author: feliperviegas
 */

#include "Koopa.h"

Koopa::Koopa():
	Enemy(500,380,40,53,100,100){
	koopa_l = Utils::load_image("resources/koopa_l.png");
	koopa_r = Utils::load_image("resources/koopa_l.png");
	moving = 1;
	spriteFrame =1;
	xVel = 10;
    int default_y = 0, default_w = 40, default_h = 53;

	clip[0].x=0;
	clip[0].y=default_y;
	clip[0].w=default_w;
	clip[0].h=default_h;

	clip[1].x=40;
	clip[1].y=default_y;
	clip[1].w=default_w;
	clip[1].h=default_h;

	clip[2].x=80;
	clip[2].y=default_y;
	clip[2].w=default_w;
	clip[2].h=default_h;
}

void Koopa::show(SDL_Surface *screen){
	if(moving == 0){
		Utils::apply_surface(this->getX(),this->getY(), koopa_l, screen,
					&clip[spriteFrame]);
	}
	if(moving == 1){
		Utils::apply_surface(this->getX(),this->getY(), koopa_r, screen,
							&clip[spriteFrame]);
	}
}

void Koopa::move(Uint32 deltaTicks){

	spriteFrame += 1;

	if(spriteFrame > 2) spriteFrame=1;

	if(moving == 1){
		this->setX( this->getX() - xVel * (deltaTicks/1000.f));
	}

	if(moving == 0){
		this->setX( this->getX() + xVel * (deltaTicks/1000.f));
	}
	if (this->getX() == 100) moving = 0;
	if (this->getX() == 500) moving = 1;
}

bool Koopa::checkCollision(SDL_Rect rect){
	return Utils::check_collision(this->getBox(),rect);
}

Koopa::~Koopa() {
	SDL_FreeSurface(koopa_l);
	SDL_FreeSurface(koopa_r);
}

