#include <iostream>
using namespace std;

int main()
{
    // Input a number
    float x;
    cout << "Enter a number to raise to the power n" << endl;
    cin >> x;
    cout << "You entered " << x << endl;

    // Input a power
    float n;
    cout << "Enter the power n" << endl;
    cin >> n;
    cout << "You entered " << n << endl;

    int sum;
    // Iterate through multiplying the number times itself
    for (int i = 0; i < n - 1; i++)
    {
        if (i == 0)
        {
            sum = x * x;
        }
        else
        {
            sum = x * sum;
        }
    }
    // Output the result
    cout << sum << endl;
    return 0;
}