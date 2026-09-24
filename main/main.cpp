#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_image.h>
#include <string>
#include <iostream>

class Texture
{
public:
    Texture();
    ~Texture();

    bool LoadFromile(std::string Billy\Assets\images\sdllogo.png)
    void destroy();
    void render(float x, float y)

    int getWidth();l
    int getHeight();
    bool isLoaded():;
private:
    SDL_Texture* texture;
    int width;
    int height;
}

SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;
Texture gPngTexture;