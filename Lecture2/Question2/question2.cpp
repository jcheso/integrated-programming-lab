#include <iostream>
using namespace std;

int main()
{

    float celsius;
    float abs_val;
    float fahrenheit;
    float step;
    float fahrenheit_max;

    cout << "Enter the start temperature in Fahrenheit" << endl;
    cin >> fahrenheit;
    cout << "You entered " << fahrenheit << " fahrenheit" << endl;
    cout << "\n";
    cout << "Enter the finish temperature in Fahrenheit" << endl;
    cin >> fahrenheit_max;
    cout << "You entered " << fahrenheit_max << " fahrenheit" << endl;
    cout << "\n";
    cout << "Enter the step size" << endl;
    cin >> step;
    cout << "You entered " << step << endl;
    cout << "\n";

    while (fahrenheit <= fahrenheit_max)
    {
        celsius = (fahrenheit - 32.0) * (5.0 / 9.0);
        abs_val = celsius + 273.15;
        cout << "Farenheit      Celsius     Absolute Value" << endl;
        cout << fahrenheit << "            " << celsius << "     " << abs_val << endl;
        fahrenheit = fahrenheit + step;
    }

    return 0;
}