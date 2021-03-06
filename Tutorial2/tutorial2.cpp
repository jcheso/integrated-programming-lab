#include <iostream>
#include <fstream>

using namespace std;

// Tutorial Exercise 2
//
// Also available from
//   http://www.doc.ic.ac.uk/~wjk/C++Intro/tut2.cpp
//
// Try to guess the output of this program using just pen and paper
// and your notes. Then use the web link above to cut and paste a
// copy of the program into emacs. Use the gdb debugger to step
// through the program slowly and to check your answer (n to step
// over statements, s to step into functions). Keep doing this
// until you understand the flow of control through the program and
// how the variables are manipulated.
//
// NB: Many aspects of the programming style in this example are
// (deliberately) awful, so please don't emulate it. Can you identify
// the main weaknesses?

char a = 'Q';
int b = 0, c = 1;
double d = 2.0;

int three(char &i, int &j, double &k)
{
    cout << "(three) entering function three" << endl;
    ofstream out;
    out.open("number.txt");
    out << "65 20 30 40 50" << endl;
    out.close();

    ifstream in;
    in.open("number.txt");
    in >> i >> b >> j;
    in >> k;
    while (!in.eof() && k < 35)
        in >> k;
    in.close();

    cout << "(three) leaving function three" << endl;
    return static_cast<int>(k / 6);

    cout << "(three) wow are we still here?" << endl;
}

int two(char &x, int y, int &z, double a)
{
    cout << "(two) entering function two" << endl;
    x = 'P';
    cout << "(two) leaving function two" << endl;
    return (y = z = static_cast<int>(a = b = 2));
}

int one(char x, int &y, int z, double &a)
{

    cout << "(one) entering function one" << endl;
    int b = 0b1010;
    y = static_cast<int>(d);
    c = three(x, y, a) + b;
    cout << "(one) leaving function one" << endl;

    return !z;
}

void print_vars()
{
    cout << "(print_vars) --> a = '" << a << "', b = " << b << ", "
         << "c = " << c << " d = " << d << endl;
}

int main()
{

    cout << sizeof(char) << endl;

    cout << sizeof(char &) << endl;

    cout << "(main) entering main" << endl;

    cout.precision(2);
    cout.setf(ios::fixed);

    print_vars();

    a = 'A';
    int b = a++;
    for (c = ++b; (c % 8); c++)
        ;

    cout << "(main) --> b = " << b << " c = " << c << endl;

    print_vars();

    if (one(a, b, c, d) && two(a, b, c, d))
    {
        cout << "(main) one and two completed!" << endl;
    }

    print_vars();

    cout << "(main) leaving main" << endl;

    return 0;

    cout << "(main) goodbye! come again soon!" << endl;
}
