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

private:
	SDL_Rect camera;
	int moving;

public:
	Camera(int x, int y, int screen_width, int screen_height);
	SDL_Rect getCamera();
	void handle_input(SDL_Event event);
	void move(Uint32 deltaTicks);
	virtual ~Camera();
};

#endif /* CAMERA_H_ */
