#include <iostream>
using namespace std;

int main()
{
    struct Vector3
    {
        int x, y, z;
    };

    // IN THE STACK
    int value = 5;
    int *ptr = &value;
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;
    Vector3 vector;

    // IN THE HEAP
    int *hvalue = new int;
    *hvalue = 5;
    int *harray = new int[5];
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;

    delete hvalue;
    delete[] harray;

    Vector3 *hvector = new Vector3();
    delete hvector;
    return 0;
}