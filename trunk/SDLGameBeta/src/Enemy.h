/*
 * Enemy.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include "MovableObject.h"
#include "VisibleObject.h"

class Enemy: public MovableObject, public VisibleObject {
public:
	Enemy(int life, int damage);
	virtual ~Enemy();
	void IA();
};

#endif /* ENEMY_H_ */
