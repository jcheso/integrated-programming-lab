#include <iostream>
using namespace std;

int main()
{

    char input_char;
    int ascii_char;

    // Read a character from the keyboard
    cout << "Input a character: " << endl;
    cin >> input_char;

    // Convert character to ASCII
    ascii_char = static_cast<int>(input_char);

    // Check if lowercase
    if (ascii_char > 96 && ascii_char < 123)
    {
        cout << "This is a lowercase letter" << endl;
    }

    // Check if uppercase
    else if (ascii_char > 64 && ascii_char < 91)
    {
        cout << "This is an uppercase letter" << endl;
    }

    // Check if not a letter
    else
    {
        cout << "This is not a lettter" << endl;
    }

    return 0;
}