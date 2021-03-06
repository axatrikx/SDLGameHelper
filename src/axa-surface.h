/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * gamehelper
 * Copyright (C) 2012 Amal Bose <amalbose@axahome>
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

#ifndef _AXA_SURFACE_H_
#define _AXA_SURFACE_H_

#include "SDL/SDL.h"
#include <iostream>

class AxaSurface
{
public:
	AxaSurface();
	
    static SDL_Surface* onLoad(char* File);

    static bool onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y);

	static bool onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H);

	static bool makeTransparent(SDL_Surface* Surf_Dest, int R, int G, int B);
protected:

private:

};

#endif // _AXA_SURFACE_H_

