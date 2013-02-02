/*
 * Hero.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "Hero.h"

Hero::Hero(int x,int y,int w,int h,int life, int damage) :
		MovableObject(x,y,w,h),GameObject(life, damage) {
}

Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

void Hero::HandleInput() {

}
