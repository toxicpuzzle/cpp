#pragma once
#include <cstdio>
#include <iostream>

class Point3d{
    int x{};
    int y{};
    int z{};

public:
    void setValues(int first, int second, int third){
        this->x = first;
        this->y = second;
        this->z = third;
    }

    void print(){
        printf("<%d,%d,%d>\n", x, y, z);
    }

    bool isEqual(Point3d other){
        return x == other.x && y == other.y && z == other.z;
    }

    int getX() const { return x; }
    int getY() const { return y; }
    int getZ() const { return z; }
};
