/*
 * StaticObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef STATICOBJECT_H_
#define STATICOBJECT_H_

#include "PhisicalObject.h"

class StaticObject: public PhisicalObject {
public:
	StaticObject(int x,int y,int w,int h);
	virtual ~StaticObject();
};

#endif /* STATICOBJECT_H_ */
