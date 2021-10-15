#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter an term to calculate the Fibonacci Sequence for: ";
    cin >> n;
    cout << "Term " << n << " of the Fibonacci sequence is " << fibonacci(n) << endl;
    return 0;
}