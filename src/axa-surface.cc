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

#include "axa-surface.h"

AxaSurface::AxaSurface() {
}

/*
 * Loads the image and returns the surface
 */
SDL_Surface* AxaSurface::onLoad(char* file) {
    SDL_Surface* Surf_Temp = NULL;
    SDL_Surface* Surf_Return = NULL;
 
    if((Surf_Temp = SDL_LoadBMP(file)) == NULL) {
		std::cout<<"ERROR: Image "<< file <<" not found";
        return NULL;
    }
 
    Surf_Return = SDL_DisplayFormat(Surf_Temp);
    SDL_FreeSurface(Surf_Temp);
 
    return Surf_Return;
}

bool AxaSurface::onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y){
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_BlitSurface(Surf_Src, NULL, Surf_Dest, &DestR);
 
    return true;
}

bool AxaSurface::onDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H) {
    if(Surf_Dest == NULL || Surf_Src == NULL) {
        return false;
    }
 
    SDL_Rect DestR;
 
    DestR.x = X;
    DestR.y = Y;
 
    SDL_Rect SrcR;
 
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W;
    SrcR.h = H;
 
    SDL_BlitSurface(Surf_Src, &SrcR, Surf_Dest, &DestR);
 
    return true;
}

bool AxaSurface::makeTransparent(SDL_Surface* Surf_Dest, int R, int G, int B) {
    if(Surf_Dest == NULL) {
        return false;
    }
 
    SDL_SetColorKey(Surf_Dest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(Surf_Dest->format, R, G, B));
 
    return true;
}