#include "statistics.h"
#include <iostream>
using namespace std;

int main()
{
    int n;
    float avg;
    float std_dev;
    float nums[4] = {0, 0, 0, 0};
    cout << "This program tests the functions in the 'statistics.h' header file." << endl;
    cout << "Do you wish to test 1, 2, 3 or 4 numbers (enter 0 to end the program):" << endl;
    cin >> n;

    if (n == 0)
    {
        cout << "Finished testing 'statistics.h' header file." << endl;
    }

    else if (n > 4)
    {
        cout << "Sorry, the program can only test 1, 2, 3 or 4 values.";
    }

    else
    {
        for (int i = 0; i <= n - 1; i++)
        {
            cout << "Enter number " << i << ": ";
            cin >> nums[i];
        }
        if (n == 1)
        {
            avg = average(nums[0]);
            std_dev = standard_deviation(nums[0]);
            cout << "Average: " << avg << ". Standard deviation: " << std_dev << ".";
        }
        else if (n == 2)
        {
            avg = average(nums[0], nums[1]);
            std_dev = standard_deviation(nums[0], nums[1]);
            cout << "Average: " << avg << ". Standard deviation: " << std_dev << ".";
        }
        else if (n == 3)
        {
            avg = average(nums[0], nums[1], nums[2]);
            std_dev = standard_deviation(nums[0], nums[1], nums[2]);
            cout << "Average: " << avg << ". Standard deviation: " << std_dev << ".";
        }
        else if (n == 4)
        {
            avg = average(nums[0], nums[1], nums[2], nums[3]);
            std_dev = standard_deviation(nums[0], nums[1], nums[2], nums[3]);
            cout << "Average: " << avg << ". Standard deviation: " << std_dev << ".";
        }
    }

    return 0;
}