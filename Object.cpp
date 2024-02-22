#ifndef Object_cpp
#define Object_cpp
#include "Object.hpp"

Object::Object(json* map){
    objectName = (*map)["name"];
    objectType = (*map)["type"];
    objectX = (*map)["x"];
    objectY = (*map)["y"];
    objectWidth = (*map)["width"];
    objectHeight = (*map)["height"];
    objectRotation = (*map)["rotation"];
    objectVisible = (*map)["visible"];
    objectProperties = (*map)["properties"];
}

Object::~Object(){
}

#endif