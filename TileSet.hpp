#ifndef TileSet_hpp
#define TileSet_hpp
#include "Config.cpp"
#include "Tile.cpp"

struct TileSet{
    TileSet(SDL_Renderer* renderer, json* map);
    ~TileSet();
    unordered_map <int, Tile*> tiles;
    SDL_Renderer* renderer;
};

#endif