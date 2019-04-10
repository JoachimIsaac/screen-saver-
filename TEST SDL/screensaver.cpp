//-------------------------------------------------------------------------------------------
//
//   Name:Joachim Isaac
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
#include "Screen.h"
using namespace std;

int main(){
    
    
    screen_of_joe::Screen screen;
    
    if(screen.init() == false){
        
        cout<<"Error initializing SDL."<<endl;
    }
    
   
    
    
  
    
    
    while(true){ // (gui loop to keep the window up.)
        //Updates particles
        //Draws particles
        //Checks for messages and events
        if(screen.processEvents() == false){
            //break;
            //This is where i'm stuck, when I put the break here it makes the program instantly close after running.
            //It seems to be a problem with my logic. Looking into it. 
            
        }
    }

    
    
    
    screen.Close();

    
    return 0;
       
}
    
    
    


    
    
    
    

