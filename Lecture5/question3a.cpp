/*
"For" loops can always be re-written as "while" loops, and vice-versa. 
Are the following two programs equivalent, and what is their output? 
Explain your answer, and run the programs to check.
*/

// No, they are not the same.
// The count initialised in the for loop is discarded each iteration, so it will stop after 4 loops.
// The count in the while loop is not being iterated, as it is within the loop scope
#include <iostream>
using namespace std;

int main()
{
    int count = 1;
    for (; count <= 5; count++)
    {
        int count = 1;
        cout << count << "\n";
    }
    return 0;
}