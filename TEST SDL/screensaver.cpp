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
            break;
            
        }
    }

    
    
    
    screen.Close();

    
    return 0;
       
}
    
    
    


    
    
    
    

