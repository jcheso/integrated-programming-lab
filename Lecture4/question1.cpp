#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_stream;
    in_stream.open("question1.cpp");
    char ch;
    in_stream.unsetf(ios::skipws);
    if (in_stream.fail())
    {
        cerr << "Cannot open file" << endl;
        return 1;
    }

    while (!in_stream.fail())
    {
        cout << ch;
        in_stream >> ch;
    }
    in_stream.close();
    return 0;
}