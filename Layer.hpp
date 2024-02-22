#ifndef Layer_hpp
#define Layer_hpp
#include "Config.cpp"
#include "TileSet.cpp"
#include "TileLayer.cpp"
#include "ObjectGroup.cpp"
#include "ImageLayer.cpp"

struct Layer{
    Layer(json* map);
    void render(TileSet* tileSet, SDL_Renderer* renderer);
    ~Layer();
    string layerName;
    string layerType; //tilelayer, objectgroup, imagelayer
    SDL_Rect* srcRect;
    int layerId;
    bool visible;
    float layerOpacity;
    TileLayer* tileLayer;
    ObjectGroup* objectGroup;
    ImageLayer* imageLayer;
};

#endif