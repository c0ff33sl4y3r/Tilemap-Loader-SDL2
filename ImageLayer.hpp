#ifndef ImageLayer_hpp
#define ImageLayer_hpp
#include "Config.cpp"

struct ImageLayer{
    ImageLayer(json* map);
    ~ImageLayer();
    string imageName;
    string imageSource;
    int imageWidth;
    int imageHeight;
    bool imageVisible;
    float imageOpacity;
    SDL_Texture* imageTexture;
};

#endif