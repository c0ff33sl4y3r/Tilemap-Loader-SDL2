#ifndef Tilecpp
#define Tilecpp
#include "Tile.hpp"

Tile::Tile(SDL_Texture* texture, SDL_Rect* srcRect, json properties = json::parse(R"###([])###")){
    this->texture = texture;
    this->srcRect = srcRect;
    this->properties = properties;
}

Tile::~Tile(){
    SDL_DestroyTexture(texture);
    delete srcRect;
}

void Tile::render(SDL_Renderer* renderer, int i, int j){
    int tilewidth = srcRect->w;
    int tileheight = srcRect->h;
    SDL_Rect destRect = {j * tilewidth, i * tileheight, tilewidth, tileheight};
    SDL_RenderCopyEx(renderer, texture, srcRect, &destRect, 0, NULL, SDL_FLIP_NONE);
}

SDL_Rect Tile::getRect(int i, int j){
    int tilewidth = srcRect->w;
    int tileheight = srcRect->h;
    SDL_Rect destRect = {j * tilewidth, i * tileheight, tilewidth, tileheight};
    return destRect;
}

#endif