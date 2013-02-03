/*
 * Config.h
 *
 *  Created on: 03/02/2013
 *      Author: isac
 */

#ifndef CONFIG_H_
#define CONFIG_H_
#include <string>
#include "Utils.h"

class Config {
private:
	string mapfilename;
	string soundfilename;
public:
	Config();
	virtual ~Config();

	string getMapfilename() const {
		return mapfilename;
	}

	void setMapfilename(string mapfilename) {
		this->mapfilename = mapfilename;
	}

	string getSoundfilename() const {
		return soundfilename;
	}

	void setSoundfilename(string soundfilename) {
		this->soundfilename = soundfilename;
	}
};

#endif /* CONFIG_H_ */
