#include <iostream>
 
int main()
{
    int stack[519000]; // So based off testing 518'000 is around the limit to the number of ints you can have on the stack (for my system). So a little over 2 MB.
    std::cout << stack[500];
    return 0;
    // So this causes the -1073741571 exit code, i.e.: stack overflow.
    // interestingly enough if you just std::cout "hi" as the tutorial suggested,
    // apparently the compiler doesn't bother actually allocating the array, and
    // thus we can get away with having insane crap like this.
}
