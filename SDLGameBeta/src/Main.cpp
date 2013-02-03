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
#include "Mario.h"
#include "Koopa.h"
#include "CheckPointBlock.h"
#include "Stage.h"

//The screen sttributes
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;

bool init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP,
			SDL_SWSURFACE);

	//If there was an error in setting up the screen
	if (screen == NULL) {
		return false;
	}

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

	SDL_WM_SetCaption("Sprite", NULL);

	//If everything initialized fine
	return true;
}

int main(int argc, char* args[]) {

	if (init() == false) {
		return 1;
	}

	Stage stage1(screen);

	stage1.setMap( new Map("resources/fase_teste.tmx") );
	stage1.setSound( new Sound("resources/sound/mp.wav"));
	stage1.setCamera( new Camera(0, 0,SCREEN_WIDTH, SCREEN_HEIGHT));
	stage1.setTimer( new Timer());
	stage1.setMario(new Mario());
	stage1.setKoopa(new Koopa());
	stage1.setCheckpointBegin(new CheckPointBlock(10,380,10,100));
	stage1.setCheckpointEnd(new CheckPointBlock(400,380,10,100));

	stage1.loop();

    Mix_CloseAudio();
	SDL_Quit();

	return 0;
}
