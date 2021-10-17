#include <iostream>
using namespace std;

int binary_search(int value, int list[], int first, int last)
{
    cout << "Value to search for: " << value << endl;
    cout << "List to search: " << list << endl;
    cout << "First list value: " << first << endl;
    cout << "Last list value: " << last << endl;
}

int main()
{

    int list[11] = {2, 2, 3, 5, 8, 14, 16, 22, 22, 24, 30};

    int first = 0;
    int last = 10;
    int value;

    cout << "Enter a value to search the array for: ";
    cin >> value;

    binary_search(value, list, first, last);

    return 0;
}