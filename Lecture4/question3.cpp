#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int count = 0;
    char ch;

    ifstream input;
    input.open("question3.cpp");

    if (input.fail())
    {
        cerr << "An Error Occured" << endl;
    }

    input.get(ch);
    while (!input.fail())
    {
        count++;
        cout << "Character: " << count << endl;
        input.get(ch);
    }

    return 0;
}