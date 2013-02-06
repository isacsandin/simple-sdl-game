/*
 * Stage.cpp
 *
 *  Created on: 03/02/2013
 *      Author: isac
 */

#include "Stage.h"

Stage::Stage(SDL_Surface *screen) {
	this->screen = screen;
	this->screenWidth = screen->w;
	this->screenHeight = screen->h;
}

void Stage::loop() {

	//The frame rate
	const int FRAMES_PER_SECOND = 8;

	bool quit = false;
	bool handle = true;
	//Start delta timer
	timer->start();

	//While the user hasn't quit
	while (quit == false) {

		Uint32 ticks = timer->get_ticks();
		if(handle){
			camera->move(ticks);
			mario->move(ticks);
		}
		koopa->move(ticks);
		mario->gravity(ticks);
		//koopa->gravity(ticks);

		//While there's events to handle
		while (SDL_PollEvent(&event)) {
			//Handle events for the dot
			sound->handleInput(event);
			if (handle) {
				mario->handleInput(event);
				camera->handleInput(event);
			}

			//If the user has Xed out the window
			if (event.type == SDL_QUIT) {
				//Quit the program
				quit = true;
			}
		}

		//Restart delta timer
		timer->start();

		//Fill the screen white
		SDL_FillRect(screen, &screen->clip_rect,
				SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

//		if (camera->checkCollision(begin->getBox())) {
//			camera->setX(camera->getX() + 100);
//		}
//
//		if (mario->checkCollision(begin->getBox())) {
//			mario->setX(mario->getX() + 20);
//		}
//		if (koopa.checkCollision(begin.getBox())){
//			koopa.setX(koopa.getX() + 20);
//		}

//		if (camera->checkCollision(end.getBox())){
//			camera->setX(camera->getX() -0);
//		}

//		if (mario->checkCollision(koopa->getBox())) {
//			mario->setX(mario->getX() - 10);
//			mario->life -= 40;
//			if (mario->life <= 0) {
//				mario->death();
//				mario->setXVel(0);
//				handle = false;
//			}
//		}
		//id 10 chão
		//id 20 bloco
		NLTmxMapLayer *layer = map->getCollisionLayer();

		for (int h = 0; h < layer->height; h++) {
			for (int w = 0; w < layer->width; w++) {

				int index = h * layer->width + w;
				int gid = layer->data[index];

				if (gid != 0) {
					int tilesetId = map->getTilesetId(gid);
					int local_id = gid
							- map->getMap()->tilesets[tilesetId]->firstGid;

					if (gid == 308) {
						SDL_Rect tile = map->getGlobalRect(w, h, tilesetId);
						tile.x -= camera->getBox().x;
						tile.y -= camera->getBox().y;

						if (mario->checkCollision(tile)) { // MORREU!
							mario->life = 0;
							if (mario->life <= 0) {
								mario->death();
								mario->setXVel(0);
								sound->playEffect("resources/sound/mario_deth.wav");
								handle = false;
							}
						}
					} else if (gid == 321) {
						SDL_Rect tile = map->getGlobalRect(w , h, tilesetId);
						tile.x -= camera->getBox().x;
						tile.y -= camera->getBox().y;

						if (mario->checkCollision(tile)) {
							mario->setX(mario->getXOld());
							mario->setY(mario->getYOld());
							cout << "PEDRINHA PORRA!!  " << gid << endl;
						}
					} else if (gid == 311) {
						SDL_Rect tile = map->getGlobalRect(w, h, tilesetId);
						tile.x -= camera->getBox().x;
						tile.y -= camera->getBox().y;
						if (mario->checkCollision(tile)) {
							cout << "COLIDIU PORRA!!  " << gid << endl;
							mario->setY(tile.y - mario->getH());
							break;
						}
					}
				}
			}
		}

		if (mario->checkCollision(end->getBox())) {
			mario->setX(mario->getX() - 20);
		}
		if (koopa->checkCollision(end->getBox())) {
			koopa->setX(koopa->getX() - 20);
		}

		//Show the tiles
		map->show(screen, camera);
		//map1.show(screen,camera);
		mario->show(screen);
		koopa->show(screen);

		SDL_Rect rect = begin->getBox();
		SDL_FillRect(screen, &rect,
				SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		rect = end->getBox();
		SDL_FillRect(screen, &rect,
				SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		//Update the screen
		if (SDL_Flip(screen) == -1) {
			return;
		}

		//Cap the frame rate
		if (timer->get_ticks() < 1000 / FRAMES_PER_SECOND) {
			SDL_Delay((1000 / FRAMES_PER_SECOND) - timer->get_ticks());
		}
	}

}

Stage::~Stage() {
	// TODO Auto-generated destructor stub
}
