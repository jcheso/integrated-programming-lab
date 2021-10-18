#include <iostream>
using namespace std;

int binary_search(int value, int list[], int first, int last)
{
    cout << "Value to search for: " << value << endl;
    cout << "List to search: " << list << endl;
    cout << "First list value: " << list[first] << " at index " << first << endl;
    cout << "Last list value: " << list[last] << " at index " << last << endl;

    int middle = (last - first) / 2 + (first);
    cout << "Middle list value: " << list[middle] << " at index " << middle << endl;
    cout << "--------------------------------------------------------------------" << endl;
    if (middle > last)
    {
        cout << "Didn't find " << value << endl;
        return false;
    }
    else if (list[middle] == value)
    {
        cout << "Found " << value << endl;
        return true;
    }
    else if (list[middle] < value)
    {
        binary_search(value, list, middle + 1, last);
    }
    else if (list[middle] > value)
    {
        binary_search(value, list, first, middle - 1);
    }
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