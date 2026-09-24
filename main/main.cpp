#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <string>

constexpr int WIDTH = 600;
constexpr int HEIGHT = 400;
SDL_Window* gWindow = nullptr;
SDL_Surface* gScreenSurface = nullptr;
SDL_Surface* gHelloWorld = nullptr;

bool init(); {
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



bool loadMedia();
void close();



int main(int argc, char* argv[]) {
    return 0;
}