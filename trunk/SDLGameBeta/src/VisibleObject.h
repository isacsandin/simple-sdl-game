/*
 * VisibleObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef VISIBLEOBJECT_H_
#define VISIBLEOBJECT_H_

class VisibleObject {
public:
	VisibleObject();
	virtual ~VisibleObject();
	virtual bool show(SDL_Surface * screen) = 0;
};

#endif /* VISIBLEOBJECT_H_ */
