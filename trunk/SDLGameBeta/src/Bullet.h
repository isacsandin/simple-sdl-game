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
#include "GameObject.h"

class Bullet: public VisibleObject, public MovableObject,public GameObject {
public:
	Bullet(int x,int y,int w,int h,int life,int damage);
	virtual ~Bullet();
};

#endif /* BULLET_H_ */
