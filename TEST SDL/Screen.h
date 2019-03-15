//
//  Screen.h
//  TEST SDL
//
//  Created by Joachim Vivian Isaac  on 3/15/19.
//  Copyright © 2019 Joachim Vivian Isaac . All rights reserved.
//

#ifndef Screen_h
#define Screen_h

#include <SDL2/SDL.h>
#include <stdio.h>
#include "Screen.h"

namespace screen_of_joe{
   
    
    class Screen{
        
    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
        
    private:
        SDL_Window * m_window;
        SDL_Renderer * m_renderer;
        SDL_Texture * m_texture;
        Uint32 * m_buffer;
        
    public:
        Screen();
        bool init();
        bool processEvents();
        void Close();
        
        
    };

}






#endif /* Screen_h */
