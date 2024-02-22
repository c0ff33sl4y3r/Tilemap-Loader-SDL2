#ifndef ObjectGroup_hpp
#define ObjectGroup_hpp
#include "Config.cpp"
#include "Object.cpp"

struct ObjectGroup{
    ObjectGroup(json* map);
    ~ObjectGroup();
    vector <Object*> objects;
};

#endif