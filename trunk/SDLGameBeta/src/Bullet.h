/*
 * Bullet.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "VisibleObject.h"
#include "MovableObject.h"

class Bullet: public VisibleObject, public MovableObject {
public:
	Bullet(int life,int damage);
	virtual ~Bullet();
};

#endif /* BULLET_H_ */
