
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Testing: " << 16 / 2 << " = " << 4 * 2 << ".\n\n";

    ifstream input;
    ofstream output;

    input.open("question2.cpp");
    output.open("WithoutComments.cpp");

    bool comment = false;
    char ch;

    input.unsetf(ios::skipws);

    if (input.fail() || output.fail())
    {
        cerr << "Cannot open file" << endl;
        return 1;
    }

    input.get(ch);

    while (!input.fail())
    {
        if (ch == '/')
        {
            input.get(ch);
            if (ch == '*')
            {
                comment = true;
                input.get(ch);
            }
            else
            {
                input.putback(ch);

                input.putback('/');
                input.get(ch);
            }
        }
        else if (ch == '*')
        {
            input.get(ch);
            if (ch == '/')
            {
                comment = false;
                input.get(ch);
            }
            else
            {
                input.putback(ch);
                input.putback('*');
                input.get(ch);
            }
        }
        if (!comment)
        {
            cout << ch;
            output << ch;
        }
        input >> ch;
    }

    input.close();
    output.close();

    return 0;
}