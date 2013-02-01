/*
 * MovableObject.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "MovableObject.h"

MovableObject::MovableObject(int x,int y,int w,int h,int life, int damage):
	PhisicalObject(x,y,w,h){
	setLife(life);
	setDamage(damage);
}

MovableObject::~MovableObject() {
}

void MovableObject::move(Uint32 deltaTicks){
	return;
}

