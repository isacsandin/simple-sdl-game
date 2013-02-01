/*
 * MovableObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef MOVABLEOBJECT_H_
#define MOVABLEOBJECT_H_

//The headers
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include "PhisicalObject.h"
#include "Timer.h"

class MovableObject: public PhisicalObject {
private:
	int life;
	int damage;
public:
	MovableObject(int life,int damage);
	virtual ~MovableObject();
	virtual void move(Uint32 deltaTicks);

	int getDamage() const {
		return damage;
	}

	void setDamage(int damage) {
		this->damage = damage;
	}

	int getLife() const {
		return life;
	}

	void setLife(int life) {
		this->life = life;
	}
};

#endif /* MOVABLEOBJECT_H_ */
