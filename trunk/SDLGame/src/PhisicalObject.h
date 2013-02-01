/*
 * PhisicalObject.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef PHISICALOBJECT_H_
#define PHISICALOBJECT_H_

//The headers
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>

class PhisicalObject {
private:
	SDL_Rect box;
public:
	PhisicalObject();
	PhisicalObject(int x,int y,int w,int h);
	virtual ~PhisicalObject();

	virtual bool CheckCollision();

	const SDL_Rect& getBox() const {
		return box;
	}

	void setBox(const SDL_Rect& box) {
		this->box = box;
	}
};

#endif /* PHISICALOBJECT_H_ */
