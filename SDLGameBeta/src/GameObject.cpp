/*
 * GameObject.cpp
 *
 *  Created on: 02/02/2013
 *      Author: isac
 */

#include "GameObject.h"

GameObject::GameObject(int life, int damage) {
	this->setLife(life);
	this->setDamage(damage);
}

GameObject::~GameObject() {
	// TODO Auto-generated destructor stub
}

