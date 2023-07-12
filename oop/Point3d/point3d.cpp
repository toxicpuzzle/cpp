#include <cstdio>
#include <iostream>

// all member functions + variables are private by default
struct Point3dStruct{
    int x{};
    int y{};
    int z{};  
};

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
};

int main()
{
    Point3d point;
    point.setValues(1, 2, 3);

    point.print();
    std::cout << '\n';

    Point3dStruct pstruct;
    pstruct.x = 0;

      Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    if (point1.isEqual(point2))
    {
        std::cout << "point1 and point2 are equal\n";
    }
    else
    {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues(3, 4, 5);

    if (point1.isEqual(point3))
    {
        std::cout << "point1 and point3 are equal\n";
    }
    else
    {
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}