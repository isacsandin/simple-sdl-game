/*
 * VisibleObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef VISIBLEOBJECT_H_
#define VISIBLEOBJECT_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <fstream>

class VisibleObject {
public:
	VisibleObject();
	virtual ~VisibleObject();
	virtual void show(SDL_Surface * screen) = 0;
};

#endif /* VISIBLEOBJECT_H_ */
