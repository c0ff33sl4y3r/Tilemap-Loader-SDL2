#ifndef Map_cpp
#define Map_cpp
#include "Map.hpp"

Map::Map(const string &name, SDL_Renderer* renderer, const json& map){
    mapName = name;
    this->renderer = renderer;
    mapWidth = map["width"];
    mapHeight = map["height"];
    tileWidth = map["tilewidth"];
    tileHeight = map["tileheight"];
    mapData = new json(map);
    for(auto& layer : map["layers"]){
        Layer* tem = new Layer(new json(layer));
        layers.push_back(tem);
    }
    if (map.find("tilesets") != map.end()){
        tileSet = new TileSet(renderer, mapData);
    }
    else{
        tileSet = NULL;
    }
}

Map::~Map(){
    delete mapData;
}

void Map::render(){
    for (auto layer: layers){
        layer->render(tileSet, renderer);
    }
}

void Map::setCollisionByProperty(json* properties, bool istrue = true){
    if (tileSet == NULL){
        cerr << "No tileset found" << endl;
        return;
    }
    for (auto tile: tileSet->tiles){
        Tile* temp = tile.second;
        unordered_map <string, json> props;
        int cnt = 0;
        for (auto property: temp->properties){
            props[property["name"]] = property["value"];
            ++cnt;
        }
        int cnt1 = 0;
        for (auto property: properties->items()){
            if (props[property.key()] == property.value()){
                ++cnt1;
            }
        }
        if (cnt == cnt1){
            cerr << "Setting collision for tile " << temp->id << endl;
            temp->isCollidable = istrue;
        }
    }

}

#endif