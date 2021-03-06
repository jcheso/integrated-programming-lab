/* C++ Programming, Program for Exercise 5, Sheet 4  */

/* Author: Rob Miller and William Knottenbelt
   Program last changed: 30th September 2001    */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char character;
    int integer;
    ofstream out_stream;
    ifstream in_stream;

    /* Create a file containing two integers */
    out_stream.open("Integers");
    out_stream << 123 << ' ' << 456;
    out_stream.close();

    /* Attempt to read a character, then an integer,
	   then a character again, then an integer again,
	   from the file "Integers" just created.         */
    in_stream.open("Integers");
    in_stream >> character >> integer;
    cout << "character: '" << character << "'\n";
    cout << "integer: " << integer << "\n";
    in_stream >> character >> integer;
    cout << "character: '" << character << "'\n";
    cout << "integer: " << integer << "\n";
    in_stream.close();

    return 0;
}

// It reads a character (single element) then an integer from the next location in the stream, until whitespace is found.