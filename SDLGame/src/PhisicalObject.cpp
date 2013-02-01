/*
 * PhisicalObject.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "PhisicalObject.h"

PhisicalObject::PhisicalObject() {
	// TODO Auto-generated constructor stub
}

PhisicalObject::PhisicalObject(int x,int y,int w,int h) {
	SDL_Rect rect = {x,y,w,h};
	this->setBox(rect);
}

PhisicalObject::~PhisicalObject() {
	// TODO Auto-generated destructor stub
}

bool PhisicalObject::CheckCollision(){
	return false;
}

