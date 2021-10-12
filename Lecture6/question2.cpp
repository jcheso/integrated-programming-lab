#include <iostream>
#include <cstring>
using namespace std;

const int MAXIMUM_LENGTH = 80;

int minimum_from(char a[], int position, int length)
{
    int min_index = position;

    for (int count = position + 1; count < length; count++)
        if (a[count] < a[min_index])
            min_index = count;

    return min_index;
}

void swap(int &first, int &second)
{
    int temp = first;
    first = second;
    second = temp;
}
void selection_sort(char a[])
{
    int length, i;
    bool length_found = false;
    while (!length_found)
    {
        if (a[i] == 0)
        {
            length = i;
            length_found = true;
        }
        i++;
    }
    for (int count = 0; count < length - 1; count++)
        swap(a[count], a[minimum_from(a, count, length)]);
}

int main()
{
    char name[MAXIMUM_LENGTH];
    cout << "Enter name: ";
    cin.getline(name, MAXIMUM_LENGTH);
    selection_sort(name);
    cout << name;
    return 0;
}