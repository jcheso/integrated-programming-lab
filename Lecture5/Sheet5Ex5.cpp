int count_character(char letter);

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  char letter;

  cout.setf(ios::left);

  /* Print table heading */
  cout.width(19);
  cout << "CHARACTER";

  cout << "OCCURRENCES" << endl
       << endl;

  /* print table of characters */
  for (letter = 'a'; letter <= 'z'; letter++)
  {
    cout.width(19);
    cout << letter;
    cout << count_character(letter) << endl;
  }

  return 0;
}

int count_character(char letter)
{

  char character;
  ifstream in_stream;

  in_stream.open("Sheet5Ex5.cpp");
  in_stream.get(character);

  int count = 0;
  while (!in_stream.fail())
  {
    if (character == letter)
      count++;
    in_stream.get(character);
  }
  in_stream.close();

  return count;
}