#include <iostream>
using namespace std;

// Function declaration
bool isPrime(int num);

int main()
{
    int num;
    // Request user input
    cout << "Enter a number to check if it is Prime" << endl;
    cin >> num;
    // Call Prime function
    isPrime(num);
    return 0;
}

// Define bool function that takes an integer
bool isPrime(int num)
{
    if (num > 1000 || num <= 1)
    {
        cout << num << " is greater than 1000, try with a smaller number" << endl;

        return false;
    }
    // Check if number is prime
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << " is not a prime number :(" << endl;

            return false;
        }
    }
    // Return True if prime between 1 - 1000.
    cout << num << " is a prime number!" << endl;

    return true;
}