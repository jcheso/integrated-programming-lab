#include <iostream>
#include <string>
using namespace std;

// Function declaration
void print_pyramid(int height);

int main()
{
    int height;
    // Explain program to user
    cout << "This program prints a 'pyramid' shape of a specified height on the screen." << endl;
    cout << "\n";
    // Prompt user for input of period height
    cout << "How high would you like the pyramid?: ";
    cin >> height;

    // prompt again if not in range
    while (height < 1 || height > 30)
    {
        cout << "Pick another height (must be between 1 and 30): ";
        cin >> height;
    }

    // Call print pyramid
    print_pyramid(height);
    return 0;
}

// Function definition print_pyramid(...)
void print_pyramid(int height)
{
    cout << "\n";
    // Print pyramid
    int i;
    int length = 2;
    int whitespace = 52;
    for (int i = 0; i <= height; i++)
    {
        cout << string(whitespace, ' ') << string(length, '*') << endl;
        length += 2;
        whitespace -= 1;
    }
}
