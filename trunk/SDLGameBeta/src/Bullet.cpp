/*
 * Bullet.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "Bullet.h"

Bullet::Bullet(int life,int damage){
	this->setLife(life);
	this->setDamage(damage);
}

Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}

