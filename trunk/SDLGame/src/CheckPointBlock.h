/*
 * CheckPointBlock.h
 *
 *  Created on: 01/02/2013
 *      Author: guineri
 */

#ifndef CHECKPOINTBLOCK_H_
#define CHECKPOINTBLOCK_H_

#include "StaticObject.h"

class CheckPointBlock: public StaticObject {
public:
	CheckPointBlock();
	virtual ~CheckPointBlock();
	bool checkColision();
};

#endif /* CHECKPOINTBLOCK_H_ */
