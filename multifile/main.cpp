#include <iostream>

/**
 * Even though add is defined in another file, it still needs to be declared
 * here either indirectly within header file or directly to allow compilation
 * via the -c flag (which stops the linking stage)
 */
int add(int x, int y);

int main(int argc, char const *argv[])
{
    std::cout << "The sum of 3 and 4 is" << add(3, 4) << "\n";
    return 0;
}
