#include <iostream>
#include "IntegerArray.h"
using namespace std;

int main()
{
    const int n = 5;
    int arr1[n];
    int arr2[n];

    double std_dev;

    cout << "Enter the values for array 1" << endl;
    input_array(arr1, n);
    cout << "You entered: ";
    display_array(arr1, n);

    cout << "Enter the values for array 2" << endl;
    input_array(arr2, n);
    cout << "You entered: ";
    display_array(arr2, n);

    cout << "Copying array 2 to array 1..." << endl;
    copy_array(arr1, arr2, n);

    cout << "Calculating the standard deviation of the array" << endl;
    std_dev = standard_deviation(arr1, n);
    cout << "The standard deviation is " << std_dev << endl;

    return 0;
}