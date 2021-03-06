/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gamehelper
 * Copyright (C) 2012 Amal Bose <axatrikx@gmail.com>
 * 
gamehelper is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gamehelper is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "game-helper.h"

#include <iostream>

GameHelper::GameHelper() {

	isRunning = true;

	Surf_Display = NULL;
	
	mainLoop();
}

/*
 *  The main loop of the class which runs as long as the isRunning variable 
 *  is set to true.
 */
int GameHelper::mainLoop() {
 if(init() == false) {
        return -1;
    }
 
    SDL_Event Event;
 
    while(isRunning) {
        while(SDL_PollEvent(&Event)) {
            handleEvents (&Event);
        }
 
        update();
        render();
    }
 
    cleanUp();
 
    return 0;
}

/*
 *  Updates the variables.
 */
void GameHelper::update () {
}

/*
 *  Draws the updated images on screen.
 */
void GameHelper::render() {

    SDL_Flip(Surf_Display);
}