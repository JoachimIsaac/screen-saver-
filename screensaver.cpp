//-------------------------------------------------------------------------------------------
//
//   Name:Joachim Isaac
//
//   Course: CMPS-1044-102, Fall 18, Dr.Tina Johnson
//
//   Purpose:
//
//
//
//
//-------------------------------------------------------------------------------------------

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>

using namespace std;

int main()
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
    
    
   //This informs us that the program didn't run successfully.
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout <<"SDL INIT FAILED."<<endl;
        return 1;
    }
    
    //This is the function call that creates the window.
    //The first thing passed in is the title of the window.
    //the second and third are special constants from the libaray that control the window size.
    //Next is screen width and hieght.
    //The last one is the flags which alter the window; by inputting SDL_WINDOW_SHOWN
    //you avoid those flags altering the window, it helps create a normal window.
    SDL_Window * window = SDL_CreateWindow("Particle Explosion",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    
    //if SDL_Window can't create a window it returns null or zero.
    //if this is the case then the quit function is called and ERROR  message is also printed.
    if (window == NULL){
        SDL_Quit();
        printf("Could not create window: %s\n", SDL_GetError());

        return 2;
    }
    
//SDL_RENDERER_PRESENTVSYNC keeps rendering under control, so that it won't render while the screen is refreshing.
SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

// This is the textures that the renderer will render.
// This controls the memory alocated to the pixels SDL_PIXELFORMAT_RGBA8888
// You can change it to get different results.
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    //Error message that is printed when the renderer is equal to zero, basically when it doesn't render.
    if(renderer == NULL){
        cout<<"Could not create renderer" << endl;
        SDL_DestroyWindow(window);//gets rid of window.
        SDL_Quit();
        return 3;
    }
   
    
    //Error message when the texture is equal to zero or when the texture is not set.
    //Also terminates the resources for sdl through sdl quit.
    if(texture == NULL){
        cout <<"Could not create texture"<<endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }
    
    //sdl's version of an in has 32bits.
    //This has the memory aviable to hold the colors.
    Uint32 * buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    bool quit = false;
    SDL_Event event;
    
    while(quit == false){ // (gui loop to keep the window up.)
        //Updates particles
        //Draws particles
        //Checks for messages and events
        
        
        
        
        
        //SDL_PollEvent feeds information into the address of event variable so that the window can be updated with the events that it stored. e.g something was clicked.
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                //If one of the events is equal to bool false then quit will equal true
                //then the while loop to keep the window opens stops. 
                quit = true;
            }
        
            }
    }
    
    
    
    
    
    
    
    delete[] buffer;
    //These are basically the sequence of the program closing
    //Gets rid of the renderering instructions
    SDL_DestroyRenderer(renderer);
    //Gets rid of the texture
    SDL_DestroyTexture(texture);
    //Gets rid of the window
    SDL_DestroyWindow(window);
    //Eliminates the resources of sdl.
    SDL_Quit();
    
    return 0;
}
