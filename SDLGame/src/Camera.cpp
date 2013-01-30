/*
 * Camera.cpp
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#include "Camera.h"

Camera::Camera(int x, int y, int screen_width, int screen_height) {

	//The camera
	camera.x = x;
	camera.y = y;
	camera.w = screen_width;
	camera.h = screen_height;
	moving = 0;

}

SDL_Rect Camera::getCamera(){
	return camera;
}

void Camera::handle_input(SDL_Event event)
{
	if( event.type == SDL_KEYDOWN )
	{
		switch( event.key.keysym.sym )
		{
			case SDLK_LEFT: moving = -1; break;
			case SDLK_RIGHT: moving = 1; break;
			default: break;

		}
	}
	else {
		if( event.type == SDL_KEYUP){
			switch( event.key.keysym.sym )
			{
				case SDLK_LEFT: moving = 0;  break;
				case SDLK_RIGHT: moving = 0; break;
				default: break;
			}
		}
	}

}

void Camera::move(Uint32 deltaTicks){
	//Scroll background
	camera.x += (100*moving);

}

Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

