/*
 * StaticEnemy.h
 *
 *  Created on: 02/02/2013
 *      Author: isac
 */

#ifndef STATICENEMY_H_
#define STATICENEMY_H_

#include "VisibleObject.h"
#include "StaticObject.h"
#include "GameObject.h"

class StaticEnemy: public VisibleObject, public StaticObject, public GameObject {
public:
	StaticEnemy(int x,int y, int w, int h, int life, int damage);
	virtual ~StaticEnemy();
};

#endif /* STATICENEMY_H_ */
