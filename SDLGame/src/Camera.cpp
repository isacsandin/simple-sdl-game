/*
 * Camera.cpp
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#include "Camera.h"

Camera::Camera(int x, int y, int screen_width, int screen_height) {

	//The camera
	camera.x = 0;
	camera.y = 0;
	camera.w = screen_width;
	camera.h = screen_height;

}

SDL_Rect Camera::getCamera(){
	return camera;
}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

