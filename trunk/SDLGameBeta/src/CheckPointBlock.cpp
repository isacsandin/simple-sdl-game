/*
 * CheckPointBlock.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "CheckPointBlock.h"

CheckPointBlock::CheckPointBlock(int x,int y,int w,int h):
	StaticObject(x,y,w,h){
}

CheckPointBlock::~CheckPointBlock() {
	// TODO Auto-generated destructor stub
}

bool CheckPointBlock::checkCollision(SDL_Rect rect){
	return Utils::check_collision(this->getBox(),rect);
}



