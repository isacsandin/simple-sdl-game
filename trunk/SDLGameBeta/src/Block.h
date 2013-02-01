/*
 * Block.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "VisibleObject.h"
#include "StaticObject.h"

class Block: public VisibleObject, public StaticObject {
public:
	Block(int x,int y,int w,int h);
	virtual ~Block();
};

#endif /* BLOCK_H_ */
