#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <string>
#include <iostream>


constexpr int WIDTH = 600;
constexpr int HEIGHT = 400;
SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gHelloWorld = nullptr;

bool init() {
    bool success = true;


    if(!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("window couldnt initialize");
        success = false;
    }

    else{
        if(gWindow = SDL_CreateWindow("My First SDL Game", WIDTH, HEIGHT, 0); gWindow == nullptr){
            SDL_Log("window couldn't be created.");
            success = false;
        }
        else{
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }

    }


    return success;

}



bool loadMedia(){
    bool success = true;

    std::string imagePath{ "../Assets/images/testforsdl.bmp" };
    gHelloWorld = SDL_LoadBMP(imagePath.c_str());
    if(gHelloWorld == nullptr){
        SDL_Log("window couldn't be created. %s", SDL_GetError());
        success = false;

    }
    return success;
}



void close(){
    SDL_DestroySurface(gHelloWorld);
    gHelloWorld = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gScreenSurface = nullptr;
    
    SDL_Quit();
}



int main(int argc, char* args[]) {
    int exitcode = 0;
    bool quit = false;
    if(init() == false){ // i know that i can use !init() but it is more readable this way
        exitcode = 1;
        bool quit = false;
    }

    else{
        if(loadMedia() == false){
            exitcode = 2;
            quit = true;
        }
        

    }
    SDL_Event e;
    SDL_zero(e);
    while(quit == false){
        while(SDL_PollEvent(&e)){
            if (e.type == SDL_EVENT_QUIT){
                quit = true;
            }
        }
        SDL_FillSurfaceRect(gScreenSurface, nullptr, SDL_MapSurfaceRGB(gScreenSurface, 0xFF, 0xFF, 0xFF));
        SDL_BlitSurface(gHelloWorld, nullptr, gScreenSurface, nullptr);
        SDL_UpdateWindowSurface(gWindow); 
    }
    close();

    std::cout << "Program Exited With ExitCode: " << exitcode << '\n';
    return 0;
}