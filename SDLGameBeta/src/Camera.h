/*
 * Camera.h
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string>
#include <fstream>
#include "MovableObject.h"
#include "Utils.h"

class Camera : public MovableObject{

private:
	int moving;

public:
	Camera(int x, int y, int w, int h);
	void handleInput(SDL_Event event);
	void move(Uint32 deltaTicks);
	bool checkCollision(SDL_Rect rect);
	virtual ~Camera();
};

#endif /* CAMERA_H_ */
