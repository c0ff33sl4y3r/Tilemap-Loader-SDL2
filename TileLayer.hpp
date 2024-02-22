#ifndef TileLayer_hpp
#define TileLayer_hpp
#include "Config.cpp"
#include "TileSet.cpp"
#include "Tile.cpp"

struct TileLayer{
    TileLayer(json* map);
    ~TileLayer();
    void render(TileSet* tileSet, SDL_Renderer* renderer);
    int layerWidth;
    int layerHeight;
    int** layerData;
};

#endif