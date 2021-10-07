#include <iostream>
using namespace std;

int main()
{

    float celsius;
    float abs_val;
    int fahrenheit = 0;
    while (fahrenheit <= 300)
    {
        celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
        abs_val = celsius + 273.15;
        cout << "Farenheit      Celsius     Absolute Value" << endl;
        cout << fahrenheit << "            " << celsius << "     " << abs_val << endl;
        fahrenheit = fahrenheit + 20;
    }

    return 0;
}