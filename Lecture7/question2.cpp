#include <iostream>
using namespace std;

bool check_bigger_string(int firstStringLength, int secondStringLength);
int check_string_length(char *string);

int main()
{
    char stringOne[] = "Two";
    char stringTwo[] = "Short";

    int firstStringLength, secondStringLength;

    firstStringLength = check_string_length(stringOne);
    secondStringLength = check_string_length(stringTwo);

    cout << check_bigger_string(firstStringLength, secondStringLength);

    return 0;
}

int check_string_length(char *string)
{
    int index = 0;
    while (*string != '\0')
    {
        index++;
        string++;
    }
    return index;
}

bool check_bigger_string(int firstStringLength, int secondStringLength)
{
    if (firstStringLength > secondStringLength)
    {
        return true;
    }
    else
    {
        return false;
    }
}