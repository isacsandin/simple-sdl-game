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

public:
	Hero(int x,int y,int w,int h,int life, int damage);
	virtual ~Hero();
	void HandleInput();
};

#endif /* HERO_H_ */
