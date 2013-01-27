#ifndef UTILS_H_
#define UTILS_H_
#include <cstdlib>
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


using namespace std;


namespace Utils {

inline SDL_Surface *load_image(string filename) {
	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized surface that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load(filename.c_str());

	//If the image loaded
	if (loadedImage != NULL) {

		//Create an optimized surface
		optimizedImage = SDL_DisplayFormat(loadedImage);

		//Free the old surface
		SDL_FreeSurface(loadedImage);

		//If the surface was optimized
		if (optimizedImage == NULL) {

			cerr<< "displayFormat error!" << endl;
			//Color key surface
			//  SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
		}
	}else{

		cerr<< "cannot load image!" << endl;

	}

	//Return the optimized surface
	return optimizedImage;
}

inline void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination,
		SDL_Rect* clip = NULL) {
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface(source, clip, destination, &offset);
}


}

#endif
