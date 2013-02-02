/*
 * StaticEnemy.cpp
 *
 *  Created on: 02/02/2013
 *      Author: isac
 */

#include "StaticEnemy.h"

StaticEnemy::StaticEnemy(int x,int y, int w, int h, int life, int damage):
	StaticObject(x,y,w,h),GameObject(life,damage){

}

StaticEnemy::~StaticEnemy() {
	// TODO Auto-generated destructor stub
}

