#include <iostream>
#include <cstdarg> // needed to use ellipsis

/**
 * Templates = way to allow function to work with different data times i.e. has generic
 * or template types, compiler can use template to generate functions as needed using actual types
*/

// Difference compared to generics
// Templates - creates new types i.e. creates duplicates of template with explicit type, Generics just restrict existing types
// https://stackoverflow.com/questions/15634970/what-makes-a-template-different-from-a-generic
// https://stackoverflow.com/questions/36347/what-are-the-differences-between-generic-types-in-c-and-java

// int max(int x, int y){
//     return (x < y) ? y : x;
// }

template<typename T, int N>
class OwnArray{

public:
    T array[N]; // N is known at compile time

    OwnArray(int count, ...){

        for (int i = 0; i < N; i++){
            array[i] = 0;
        }

        std::cout << "The count is " << count << "\n";
        // Initialise ellipses list
        std::va_list list;
        va_start(list, count);

        for (int i = 0; i < count; i++){
            array[i] = va_arg(list, T); // pulls the next element off the list
        }

        va_end(list);
    }

    T& operator[](int i){
        return array[i];
    }

    int getSize() const{
        return N; 
    }
};

template<typename T>
T max(T x, T y){
    return (x < y) ? y : x;
}

// Go over function templates and class templates and their relationship to generics
int main(){
    int (*x)(int, int) = [](int x, int y){
        return 10;
    };

    std::cout << x(1,1) << "\n";
    std::cout << max(1.0, 2.2) << "\n";
    std::cout << max<double>(1, 2.2) << "\n"; // this would be allowed but max(1,2.2) not because compilers does not do type conversions when doing template argument deduction, but if compiler knew the arguments explicitly like here, it would do convert mismatched args

    // avoid ellipses whenever as compiler forgets typechecking!
    OwnArray<int, 10> arr{5,1,2,3,4,5}; //! Need to provide num of args in count, 
    arr[0] = 100;

    for (int i =0; i < 10; i++){
        std::cout << arr[i] << "\n";
    }
}