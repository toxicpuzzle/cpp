
#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "add.h"

int multiply(int x, int y){
    int result{0};
    for (int i = 0; i < y; i++){
        result += x;
    }
    return result;
}

#endif