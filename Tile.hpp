#ifndef Tile_hpp
#define Tile_hpp
#include "Config.cpp"

struct Tile{
    Tile(SDL_Texture* texture, SDL_Rect* srcRect, json properties);
    ~Tile();
    void render(SDL_Renderer* renderer, int i, int j);
    SDL_Rect getRect(int i, int j);
    json properties;
    bool isCollidable;
    SDL_Texture* texture;
    SDL_Rect* srcRect;
    int id;
};

#endif