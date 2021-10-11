#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char ch;
    bool eof_hit;
    int ch_num = 0, ch_location = 0;

    ifstream input;
    input.open("question4.cpp");

    if (input.fail())
    {
        cerr << "An error occured opening the file" << endl;
    }

    while (!input.eof())
    {
        // cout << input.tellg() << endl;
        input.get(ch);
        ch_num++;
    }

    eof_hit = true;
    input.close();

    while (eof_hit && ch_num >= 0)
    {
        ifstream input;
        input.open("question4.cpp");
        input.get(ch);
        while (ch_location != ch_num)
        {
            input.get(ch);
            ch_location++;
        }
        cout << ch;
        ch_num -= 1;
        ch_location = 0;
    }
    return 0;
}