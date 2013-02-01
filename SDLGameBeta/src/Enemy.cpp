/*
 * Enemy.cpp
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#include "Enemy.h"

Enemy::Enemy(int x,int y,int w,int h,int life, int damage)
	:MovableObject(x,y,w,h,life,damage),VisibleObject(){
}

Enemy::~Enemy() {
	// TODO Auto-generated destructor stub
}

void Enemy::IA(){
	return;
}

