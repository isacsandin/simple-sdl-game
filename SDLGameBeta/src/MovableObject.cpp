/*
 * MovableObject.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "MovableObject.h"

MovableObject::MovableObject(int life, int damage) {
	setLife(life);
	setDamage(damage);
}

MovableObject::MovableObject() {
}

MovableObject::~MovableObject() {
	// TODO Auto-generated destructor stub
}

void MovableObject::move(Uint32 deltaTicks){
	return;
}

