/*
 * Bullet.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "Bullet.h"

Bullet::Bullet(int x,int y,int w,int h,int life,int damage):
	MovableObject(x,y,w,h,life,damage),VisibleObject(){
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

