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

class Camera {

	//The camera
	SDL_Rect camera;

public:
	Camera(int x, int y, int screen_width, int screen_height);
	SDL_Rect getCamera();
	virtual ~Camera();
};

#endif /* CAMERA_H_ */
