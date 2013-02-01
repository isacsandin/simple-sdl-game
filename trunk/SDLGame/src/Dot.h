///*
// * Dot.h
// *
// *  Created on: 26/01/2013
// *      Author: isac
// */
//
//#ifndef DOT_H_
//#define DOT_H_
//#include "Utils.h"
//#include <vector>
//#include <SDL/SDL.h>
//
//
//
//class Dot {
//
//    private:
//    //The X and Y offsets of the dot
//    float x, y;
//
//    //The velocity of the dot
//    float xVel, yVel;
//
//	int moving;
//
//	bool down;
//	bool crouched;
//	bool climbing_s,climbing_started;
//
//	bool up,up_s;
//	bool jump,jump_done,jump_started;
//	int jump_alt;
//
//	bool shot_s,shot_ready,shot_started,shoted;
//
//	bool death_s,death_started;
//
//	int SCREEN_WIDTH;
//	int SCREEN_HEIGHT;
//
//	//The portions of the sprite map to be blitted
//	SDL_Rect clip[ 70 ];
//
//	int animations[10]; 	// 0 - Moving
//							// 1 - Stationary
//							// 2 - Crouched
//							// 3 - Jump
//							// 4 - Shooting
//							// 5 - Dying
//							// 6 - Climbing
//							// 7 - Falling
//
//	int sprite_frame;
//
//	//The attributes of the dot
//	const static int DOT_WIDTH = 20;
//	const static int DOT_HEIGHT = 20;
//	const static int DOT_VEL = 5;
//
//	SDL_Surface *dot_l;
//	SDL_Surface *dot_r;
//
//    public:
//    //Initializes the variables
//    Dot(int screen_width, int screen_height);
//
//    //Takes key presses and adjusts the dot's velocity
//    void handle_input(SDL_Event event);
//
//    //Moves the dot
//    void move( Uint32 deltaTicks );
//
//    //Shows the dot on the screen
//    void show(SDL_Surface *screen);
//
//    int shot();
//
//    int death();
//
//    void clean_up();
//
//	virtual ~Dot();
//
//	bool load_files();
//
//};
//
//#endif /* DOT_H_ */


/*
 * Dot.h
 *
 *  Created on: 26/01/2013
 *      Author: isac
 */

#ifndef DOT_H_
#define DOT_H_
#include "Utils.h"
#include <vector>
#include <SDL/SDL.h>



class Dot {

    private:
    //The X and Y offsets of the dot
    float x, y;

    //The velocity of the dot
    float xVel, yVel;

	int moving;

	bool down;
	bool crouched;
	bool climbing_s,climbing_started;

	bool up,up_s;
	bool jump,jump_done,jump_started;
	int jump_alt;

	bool shot_s,shot_ready,shot_started,shoted;

	bool death_s,death_started;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	//The portions of the sprite map to be blitted
	SDL_Rect clip[ 70 ];

	int animations[10]; 	// 0 - Moving
							// 1 - Stationary
							// 2 - Crouched
							// 3 - Jump
							// 4 - Shooting
							// 5 - Dying
							// 6 - Climbing
							// 7 - Falling

	int sprite_frame;

	//The attributes of the dot
	const static int DOT_WIDTH = 20;
	const static int DOT_HEIGHT = 20;
	const static int DOT_VEL = 5;

	SDL_Surface *dot_l, *dot_r;

    public:
    //Initializes the variables
    Dot(int screen_width, int screen_height);

    //Takes key presses and adjusts the dot's velocity
    void handle_input(SDL_Event event);

    //Moves the dot
    void move( Uint32 deltaTicks );

    //Shows the dot on the screen
    void show(SDL_Surface *screen);

    int shot();

    int death();

    void clean_up();

	virtual ~Dot();

	bool load_files();

};

#endif /* DOT_H_ */
