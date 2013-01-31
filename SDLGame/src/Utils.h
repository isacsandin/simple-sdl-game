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
		if (optimizedImage != NULL) {

			//Color key surface
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY,
					SDL_MapRGB(optimizedImage->format, 0, 0xFF, 0xFF));

		} else {
			cerr << "displayFormat error!" << endl;
		}

	} else {

		cerr << "cannot load image! " << filename << endl;

	}

	//Return the optimized surface
	return optimizedImage;
}

inline void apply_surface(int x, int y, SDL_Surface* source,
		SDL_Surface* destination, SDL_Rect* clip = NULL) {
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface(source, clip, destination, &offset);
}

inline bool check_collision( SDL_Rect A, SDL_Rect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

inline void* loadFile( const char * filename, bool appendNull ) {

    FILE* f = fopen( filename, "r" );
    if ( !f ) {
        return 0;
    }

    fseek( f, 0, SEEK_END );
    auto length = ftell( f ) + appendNull;
    fseek( f, 0, SEEK_SET );

    void* buffer = malloc( length );
    fread( buffer, length, 1, f );
    fclose( f );

    if ( appendNull ) {
        ((char*)buffer)[ length-1 ] = 0;
    }

    return buffer;
}

}

#endif
