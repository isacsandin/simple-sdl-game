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

	virtual bool checkCollision(SDL_Rect rect) = 0;

	const SDL_Rect& getBox() const {
		return box;
	}

	void setBox(const SDL_Rect& box) {
		this->box = box;
	}

	int getX() const {
		return box.x;
	}

	void setX(int x) {
		this->box.x = x;
	}

	int getY() const {
		return box.y;
	}

	void setY(int y) {
		this->box.y = y;
	}

	int getW() const {
		return box.w;
	}

	void setW(int w) {
		this->box.w = w;
	}

	int getH() const {
		return box.h;
	}

	void setH(int h) {
		this->box.h = h;
	}
};

#endif /* PHISICALOBJECT_H_ */
