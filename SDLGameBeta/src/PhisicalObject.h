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
	SDL_Rect boxOld;
public:
	PhisicalObject();
	PhisicalObject(int x,int y,int w,int h);
	virtual ~PhisicalObject();

	virtual bool checkCollision(SDL_Rect rect);

	SDL_Rect getBox(){
		return box;
	}

	void setBox(const SDL_Rect& box) {
		this->box = box;
	}

	int getX() const {
		return box.x;
	}

	int getXOld() const {
			return boxOld.x;
	}

	void setX(int x) {
		setXOld(getX());
		this->box.x = x;
	}

	void setXOld(int x) {
			this->boxOld.x = x;
	}

	int getY() const {
		return box.y;
	}

	int getYOld() const {
			return boxOld.y;
	}

	void setY(int y) {
		setYOld(getY());
		this->box.y = y;
	}

	void setYOld(int y) {
			this->boxOld.y = y;
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

	const SDL_Rect& getBoxOld() const {
		return boxOld;
	}

	void setBoxOld(const SDL_Rect& boxOld) {
		this->boxOld = boxOld;
	}
};

#endif /* PHISICALOBJECT_H_ */
