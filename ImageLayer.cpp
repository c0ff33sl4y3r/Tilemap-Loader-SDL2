#ifndef ImageLayer_cpp
#define ImageLayer_cpp
#include "ImageLayer.hpp"

ImageLayer::ImageLayer(json* map){
    imageSource = (*map)["image"];
    imageWidth = (*map)["imagewidth"];
    imageHeight = (*map)["imageheight"];
}

ImageLayer::~ImageLayer(){
}

#endif