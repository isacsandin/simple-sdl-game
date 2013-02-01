/*
 * Hero.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef HERO_H_
#define HERO_H_

#include "MovableObject.h"
#include "VisibleObject.h"

class Hero: public MovableObject, public VisibleObject {
private:
	int life;
	int damage;

public:
	Hero(int life, int damage);
	virtual ~Hero();
	void HandleInput();

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

#endif /* HERO_H_ */
