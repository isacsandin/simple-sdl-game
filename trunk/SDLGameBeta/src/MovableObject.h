/*
 * MovableObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef MOVABLEOBJECT_H_
#define MOVABLEOBJECT_H_

//The headers
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include "PhisicalObject.h"
#include "Timer.h"
#include "Physics.h"

class MovableObject: public PhisicalObject{
public:
	MovableObject(int x, int y, int w, int h);
	virtual ~MovableObject();
	virtual void move(Uint32 deltaTicks) = 0;
};

#endif /* MOVABLEOBJECT_H_ */
