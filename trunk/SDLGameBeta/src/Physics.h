/*
 * Physics.h
 *
 *  Created on: 03/02/2013
 *      Author: guineri
 */

#ifndef PHYSICS_H_
#define PHYSICS_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>

class Physics {
public:
	Physics();
	virtual ~Physics();
	virtual void gravity(Uint32 dt)=0;
	virtual void impulse(Uint32 dt)=0;

	const float getAcGravity() const {
		return acGravity;
	}

	const float getImpulseFactor() const {
		return impulseFactor;
	}

private:
	float const acGravity = 100; //Gravity acceleration
	float const impulseFactor = 1; //Impulse factor
};

#endif /* PHYSICS_H_ */
