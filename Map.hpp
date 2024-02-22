#ifndef Map_hpp
#define Map_hpp
#include "Config.cpp"
#include "Layer.cpp"

struct Map{
    Map(const string &name, SDL_Renderer* renderer, const json& map);
    ~Map();
    void setCollisionByProperty(json* properties, bool istrue);
    void render();
    string mapName;
    int mapWidth;
    int mapHeight;
    int tileWidth;
    int tileHeight;
    json* mapData;
    SDL_Renderer *renderer;
    TileSet* tileSet;
    vector <Layer*> layers;
};

#endif