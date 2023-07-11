#include <iostream>

int main()
{
    [[maybe_unused]] int a; // no (default) initialisation - i.e. junk value
    int x = 1;              // Copy initialisation - copies RHS value to var (slow)
    int width(5);           // direct initialisation - for complex objects e.g. classes (bad)
    int height { 5 };       // list initialisation (recommended) - more consistent syntax to initialise obj with list of values
    int length{};           // value initialisation - initialises value (for temporary values)
    // int error { 5.6 };           // List Init prevents narrowing conversion (downcasting) from being possible compared to copy init
    
    // cout - std output stream we send chars to using insertion "<<" operator
    // << can be used for concatenating strings together for insertion
    // endl - is "\n" + flushes output buffer at end of each line -> PREFER \n
    std::cout << "Hello world" << x << " " << width << " " << height << " " << length << " " << std::endl;
    std::cout << "Look at me I'm on a new line!" << std::endl;
    std::cout << "hello" + 2 << "\n"; // Prints llo because the string is a pointer and adding 2 increments by 2 chars
    std::cout << 2+5 << "\n"; // Prints 7 because operation inside << << operators are conducted first.
    // std::cout << "hello" + " it's me" << "\n"; // + operator between strings is not supported for char pointers in C++

    // >> extraction operator for moving data from input to variable
    std::cout << "Enter two number(s)" << "\n";
    int input{}, input2{};
    std::cin >> input >> input2; // either "2\n3\n" or "2 3\n" will do input=2, input2=3
    std::cout << "The number(s) you have entered are: " << input << " " << input2 << "\n";
    // Errors
        //  input = h: returns 0
        //  input = 3.2: output 3 i.e. drops fractional component NB: narrowing conversion restriction for list init only applies on init not on assignment
        //  input = 123abc output 123

    // Iteration
    [[maybe_unused]] int array[]{1,2,3,4,5}; // Initialise array with 5 values
    [[maybe_unused]] int twoDimensionalArray[][3]{{1,2,3},{4,5,6},{7,8,9}}; // 2d array init just needs last element init done

    // For int loops
    for (std::size_t i = 0; i < std::size(twoDimensionalArray); i++){
        int *row{twoDimensionalArray[i]}; 
        std::cout << sizeof(*row) << " " << sizeof(int) << "\n"; // sizeof(*row), *row is 2da[i][0] i.e. int
        for (std::size_t j = 0; j < 3; j++){ 
            std::cout << "Number is " << row[j] << "\n";
        }
    }

    // For each loops
    for (int var: array){
        std::cout << "Number is " << var << "\n";
    }
    
    // for (int* row: twoDimensionalArray){
    //     for (int cell: *row){
    //         std::cout << "Number is " << cell << "\n";
    //     }
    // }

}