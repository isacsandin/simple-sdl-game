/*
 * GameObject.h
 *
 *  Created on: 02/02/2013
 *      Author: isac
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

class GameObject {
private:
	int life;
	int damage;
public:
	GameObject(int life,int damage);
	virtual ~GameObject();

	int getDamage() const {
		return damage;
	}

	void setDamage(int damage) {
		this->damage = damage;
	}

	int getLife() const {
		return life;
	}

	void setLife(int life) {
		this->life = life;
	}
};

#endif /* GAMEOBJECT_H_ */
