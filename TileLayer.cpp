#ifndef TileLayer_cpp
#define TileLayer_cpp
#include "TileLayer.hpp"

TileLayer::TileLayer(json* map){
    layerWidth = (*map)["width"];
    layerHeight = (*map)["height"];
    layerData = new int*[layerHeight];
    for (int i = 0; i < layerHeight; i++){
        layerData[i] = new int[layerWidth];
        for (int j = 0; j < layerWidth; j++){
            layerData[i][j] = (*map)["data"][i * layerWidth + j];
        }
    }
}

TileLayer::~TileLayer(){
    for (int i = 0; i < layerHeight; i++){
        delete[] layerData[i];
    }
    delete[] layerData;
}

void TileLayer::render(TileSet* tileSet, SDL_Renderer* renderer){
    for (int i = 0; i < layerHeight; i++){
        for (int j = 0; j < layerWidth; j++){
            int id = layerData[i][j];
            if (id != 0){
                Tile* tile = tileSet->tiles[id];
                tile->render(renderer, i, j);
            }
        }
    }
}

#endif