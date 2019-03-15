//
//  Screen.cpp
//  TEST SDL
//
//  Created by Joachim Vivian Isaac  on 3/15/19.
//  Copyright © 2019 Joachim Vivian Isaac . All rights reserved.
//


#include "Screen.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include "Screen.h"



namespace screen_of_joe {
    
   screen_of_joe::Screen::Screen():
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){
        
        
    }
    
    
    
         bool Screen::init(){
        //This informs us that the program didn't run successfully.
        if(SDL_Init(SDL_INIT_VIDEO)<0){
            
            return false;
        }
        
        //This is the function call that creates the window.
        //The first thing passed in is the title of the window.
        //the second and third are special constants from the libaray that control the window size.
        //Next is screen width and hieght.
        //The last one is the flags which alter the window; by inputting SDL_WINDOW_SHOWN
        //you avoid those flags altering the window, it helps create a normal window.
        m_window = SDL_CreateWindow("Particle Explosion",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        
        //if SDL_Window can't create a window it returns null or zero.
        //if this is the case then the quit function is called and ERROR  message is also printed.
        if (m_window == NULL){
            SDL_Quit();
            // printf("Could not create window: %s\n", SDL_GetError());
            
            return false;
        }
        
        //SDL_RENDERER_PRESENTVSYNC keeps rendering under control, so that it won't render while the screen is refreshing.
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        
        // This is the textures that the renderer will render.
        // This controls the memory alocated to the pixels SDL_PIXELFORMAT_RGBA8888
        // You can change it to get different results.
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
                                      SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        //Error message that is printed when the renderer is equal to zero, basically when it doesn't render.
        if(m_renderer == NULL){
            
            SDL_DestroyWindow(m_window);//gets rid of window.
            SDL_Quit();
            return false;
        }
        
        
        //Error message when the texture is equal to zero or when the texture is not set.
        //Also terminates the resources for sdl through sdl quit.
        if(m_texture == NULL){
            
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }
        
        //sdl's version of an in has 32bits.
        //This has the memory aviable to hold the colors.
        Uint32 * buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        
        //memset allows you to set a block of memory with a particular value
        //SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32) is the amount of
        //pixel memory needed for the entire screen.
        //255 = 0xff in hexadecimal.
        //255 is a color it is the limit of the range of colors
        memset(buffer,0,SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
        
        //each pair of ffs set a value for each red blue or green.
        buffer[30000] = 0xFFFFFFFF;
        //This loop sets all the colors of each particle based on the hexadecimal number
        for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT;i++){
            buffer[i] = 0x080080FF;
        }
        
        //updates the texture (rendering code)
        SDL_UpdateTexture(m_texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
        
        
        return true;
    }
    
    
    bool Screen::processEvents(){
        //SDL_PollEvent feeds information into the address of event variable so that the window can be updated with the events that it stored. e.g something was clicked.
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                //If one of the events is equal to bool false then quit will equal true
                //then the while loop to keep the window opens stops.
                return false;
            }
            
        }
        
        return false;
    }
    
    
    void Screen::Close(){
        
        delete[] m_buffer;
        //These are basically the sequence of the program closing
        //Gets rid of the renderering instructions
        SDL_DestroyRenderer(m_renderer);
        //Gets rid of the texture
        SDL_DestroyTexture(m_texture);
        //Gets rid of the window
        SDL_DestroyWindow(m_window);
        //Eliminates the resources of sdl.
        SDL_Quit();
    }
}
