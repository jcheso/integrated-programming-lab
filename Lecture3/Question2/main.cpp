/* This program prints out a conversion table of temperatures, after
	prompting the user for upper and lower bounds of the table in
        Fahrenheit, and the temperature difference between table entries. */

#include "conversions.h"
#include <iostream>
using namespace std;

void print_preliminary_message();

void input_table_specifications(int &lower, int &upper, int &step);

void print_message_echoing_input(int lower, int upper, int step);

void print_table(int lower, int upper, int step);

/* START OF MAIN PROGRAM */
int main()
{
    int lower = 0; /* the lowest Fahrenheit entry in the table */
    int upper = 0; /* the highest Fahrenheit entry in the table */
    int step = 1;  /* difference in Fahrenheit between entries */

    /* print a message explaining what the program does: */
    print_preliminary_message();

    /* prompt the user for table specifications in Fahrenheit: */
    input_table_specifications(lower, upper, step);

    /* print appropriate message including an echo of the input: */
    print_message_echoing_input(lower, upper, step);

    /* Print the table (including the column headings): */
    print_table(lower, upper, step);

    return 0;
}
/* END OF MAIN PROGRAM */

void print_preliminary_message()
{
    cout << "This program prints out a conversion table of temperatures." << endl;
}

void input_table_specifications(int &lower, int &upper, int &step)
{
    cout << "Enter the start temperature in Fahrenheit" << endl;
    cin >> lower;

    cout << "Enter the finish temperature in Fahrenheit" << endl;
    cin >> upper;

    cout << "Enter the step size" << endl;
    cin >> step;
}

void print_message_echoing_input(int lower, int upper, int step)
{
    cout << "You entered " << lower << " fahrenheit" << endl;
    cout << "\n";
    cout << "You entered " << upper << " fahrenheit" << endl;
    cout << "\n";
    cout << "You entered " << step << endl;
    cout << "\n";
}

void print_table(int lower, int upper, int step)
{
    float celsius;
    float abs_val;
    while (lower <= upper)
    {
        celsius = celsius_of(lower);
        abs_val = absolute_value_of(lower);
        cout << "Farenheit  "
             << "Celsius    "
             << "Absolute Value " << endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << lower << "      " << celsius << "       " << abs_val << endl;
        lower = lower + step;
    }
}
