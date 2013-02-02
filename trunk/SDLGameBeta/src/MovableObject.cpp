/*
 * MovableObject.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "MovableObject.h"

MovableObject::MovableObject(int x,int y,int w,int h):
	PhisicalObject(x,y,w,h){
}

MovableObject::~MovableObject() {
}

void MovableObject::move(Uint32 deltaTicks){
	return;
}

