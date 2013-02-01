/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
 and may not be redistributed without written permission.*/

//The headers
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <string>
#include "Timer.h"
#include "Sound.h"
#include "Camera.h"
#include "Map.h"


//The screen sttributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;



//The frame rate
const int FRAMES_PER_SECOND = 8;

//The surfaces

SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;


bool init() {
	//Initialize all SDL subsystems
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
			SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if (screen == NULL) {
		return false;
	}

    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

	//Set the window caption
	SDL_WM_SetCaption("Sprite", NULL);

	//If everything initialized fine
	return true;
}

int main(int argc, char* args[]) {
	//Quit flag
	bool quit = false;
	//Initialize
	if (init() == false) {
		return 1;
	}

	Map map("resources/background.tmx");
	//Map map1("resources/background1.tmx");

	Sound sound;

	Camera *camera = new Camera(0, 0,SCREEN_WIDTH, SCREEN_HEIGHT);

	//Keeps track of time since last rendering
	Timer delta;

	//Start delta timer
	delta.start();

	//While the user hasn't quit
	while (quit == false) {

		Uint32 ticks = delta.get_ticks();
		camera->move(ticks);

		//While there's events to handle
		while (SDL_PollEvent(&event)) {
			//Handle events for the dot
			sound.handle_input(event);
			camera->handle_input(event);

			//If the user has Xed out the window
			if (event.type == SDL_QUIT) {
				//Quit the program
				quit = true;
			}
		}

		//Restart delta timer
		delta.start();

		//Fill the screen white
		SDL_FillRect(screen, &screen->clip_rect,
				SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));

		//Show the tiles
		map.show(screen,camera);
		//map1.show(screen,camera);

		//Update the screen
		if (SDL_Flip(screen) == -1) {
			return 1;
		}

		//Cap the frame rate
		if (delta.get_ticks() < 1000 / FRAMES_PER_SECOND) {
			SDL_Delay((1000 / FRAMES_PER_SECOND) - delta.get_ticks());
		}

	}

	//Clean up
    Mix_CloseAudio();
	SDL_Quit();

	return 0;
}
