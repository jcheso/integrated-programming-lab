#include <iostream>
using namespace std;

int greatest_common_divisor(int m, int n)
{
    if (m > n)
    {
        return greatest_common_divisor(m - n, n);
    }
    else
    {
        return m;
    }
}

int main()
{
    int m = 20, n = 5;
    cout << greatest_common_divisor(m, n);

    return 0;
}