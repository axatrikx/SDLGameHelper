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

#ifndef _AXA_ANIMATION_H_
#define _AXA_ANIMATION_H_


#include <SDL.h>
 
class AxaAnimation {
    private:
        int    currentFrame;
 
        int     frameInc;
 
        int     frameRate; //Milliseconds
 
        long    oldTime;
 
    public:
        AxaAnimation();
 
        int    maxFrames;
 
        bool    oscillate;
 
        void	onAnimate();
 
        void	setFrameRate(int Rate);
 
        void setCurrentFrame(int Frame);
 
        int getCurrentFrame();
};

#endif // _AXA_ANIMATION_H_

