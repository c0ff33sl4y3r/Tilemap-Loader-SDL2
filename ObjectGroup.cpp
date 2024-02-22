#ifndef ObjectGroup_cpp
#define ObjectGroup_cpp
#include "ObjectGroup.hpp"

ObjectGroup::ObjectGroup(json* map){
    for (auto& object : (*map)["objects"]){
        objects.push_back(new Object(new json(object)));
    }
}

ObjectGroup::~ObjectGroup(){
    for (auto object: objects){
        delete object;
    }
}

#endif