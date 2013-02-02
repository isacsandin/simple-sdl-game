/*
 * Camera.cpp
 *
 *  Created on: 29/01/2013
 *      Author: feliperviegas
 */

#include "Camera.h"

Camera::Camera(int x, int y, int w, int h):
	MovableObject(x,y,w,h){
	moving = 0;

}

void Camera::handleInput(SDL_Event event)
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
	this->setX( this->getX()+(100*moving) );

}

bool Camera::checkCollision(SDL_Rect rect){
	return Utils::check_collision(this->getBox(),rect);
}


Camera::~Camera() {
	// TODO Auto-generated destructor stub
}

