// Header guards ensure preprocessor does not copy copy definition of
// Same function/type twice (when you put definitions in headers)
#ifndef ADD_H
#define ADD_H

int add(int x, int y){
    return x + y;
}

#endif