#ifndef TileSet_cpp
#define TileSet_cpp
#include "Tileset.hpp"

TileSet::TileSet(SDL_Renderer* renderer, json* map){
    this->renderer = renderer;
    if (map->find("tilesets") != map->end()){
        for (auto& tileset : (*map)["tilesets"]){
            int firstgid = tileset["firstgid"];
            int tilecount = tileset["tilecount"];
            if (tileset.find("image") == tileset.end()){
                for (auto& tile : tileset["tiles"]){
                    int id = tile["id"];
                    SDL_Texture* texture = loadTexture(tile["image"], renderer);
                    SDL_Rect* srcRect = new SDL_Rect({0, 0, tileset["tilewidth"], tileset["tileheight"]});
                    if (tile.find("properties") != tile.end()){
                        tiles[firstgid + id] = new Tile(texture, srcRect, tile["properties"]);
                    }
                    else{
                        tiles[firstgid + id] = new Tile(texture, srcRect);
                    }
                    tiles[firstgid + id]->id = firstgid + id;
                    tiles[firstgid + id]->isCollidable = false;
                }
            }
            else{
                // Calculate the number of rows (tilecount / columns)
                int columns = tileset["columns"];
                int rows = tilecount / columns;
                int tidewidth = tileset["tilewidth"];
                int tileheight = tileset["tileheight"];
                SDL_Texture* texture = loadTexture(tileset["image"], renderer);
                for (int i = 0; i < rows; i++){
                    for (int j = 0; j < columns; j++){
                        int id = firstgid + i * columns + j;
                        SDL_Rect* srcRect = new SDL_Rect({j * tidewidth, i * tileheight, tidewidth, tileheight});
                        if (tileset.find("tiles") != tileset.end() && tileset["tiles"].find("properties") != tileset["tiles"].end()){
                            tiles[id] = new Tile(texture, srcRect, tileset["tiles"]["properties"]);
                        }
                        else{
                            tiles[id] = new Tile(texture, srcRect);
                        }
                        tiles[id]->id = id;
                        tiles[id]->isCollidable = false;
                    }
                }
            }
        }
    }
}

TileSet::~TileSet(){
    for (auto tile: tiles){
        delete tile.second;
    }
}

#endif