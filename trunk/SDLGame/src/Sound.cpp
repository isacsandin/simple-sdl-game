/*
 * Sound.cpp
 *
 *  Created on: 29/01/2013
 *      Author: isac
 */

#include "Sound.h"

Sound::Sound() {
	//The music that will be played
	music = NULL;
	music = Mix_LoadMUS( "resources/Legend Of Zelda Four Swords Theme.wav" );
	Mix_PlayMusic( music, -1 );

}

int Sound::handle_input(SDL_Event event){

    if( event.type == SDL_KEYDOWN )
          {
              //If 9 was pressed
              if( event.key.keysym.sym == SDLK_9 )
              {
                  //If there is no music playing
                  if( Mix_PlayingMusic() == 0 )
                  {
                      //Play the music
                      if( Mix_PlayMusic( music, -1 ) == -1 )
                      {
                          return 1;
                      }
                  }
                  //If music is being played
                  else
                  {
                      //If the music is paused
                      if( Mix_PausedMusic() == 1 )
                      {
                          //Resume the music
                          Mix_ResumeMusic();
                      }
                      //If the music is playing
                      else
                      {
                          //Pause the music
                          Mix_PauseMusic();
                      }
                  }
              }
              //If 0 was pressed
              else if( event.key.keysym.sym == SDLK_0 )
              {
                  //Stop the music
                  Mix_HaltMusic();
              }
              else if( event.key.keysym.sym == SDLK_SPACE )
              {

            	  playEffect("resources/mario_jump.wav");

              }
          }
    return 0;

}

void Sound::playEffect(string filename){
	Mix_Chunk *effect = NULL;
	effect = Mix_LoadWAV(filename.c_str());
    Mix_PlayChannel( -1, effect, 0 );
    Mix_FreeChunk( effect );

}

Sound::~Sound() {
    Mix_FreeMusic( music );
}

