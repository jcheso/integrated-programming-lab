/*
(a) What happens (and why) if we try to replace the "switch" statement with the single line

	cout << static_cast<Day>(count);         ?

 ** It outputs the integer of the day instead of the name of the day **

Replace the "switch" statement with the line
	print_day(static_cast<Day>(count), cout);
instead, and add an appropriate definition after the main program for the function "print_day(...)", 
using a "switch" statement (don't forget the function declaration as well). ("cout" is of type or class "ostream").

(b) The shop keeper wants to change the closing times to 1pm on Sundays, 5pm on Saturdays, 8pm on Wednesdays, 
and 6pm all other days. Make appropriate changes to the function "closing_time(...)" using a "switch" statement, and test the program.
*/

#include <iostream>
using namespace std;

enum Day
{
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

int closing_time(Day day_of_the_week);
void print_day(Day count, ostream &out);

/* MAIN PROGRAM */
int main()
{
    int count;

    cout.setf(ios::left);
    /* Print table heading */
    cout.width(17);
    cout << "DAY";
    cout << "CLOSING TIME\n\n";

    /* Print table from Sunday to Saturday */
    for (count = static_cast<int>(Sun); count <= static_cast<int>(Sat); count++)
    {
        cout.width(19);
        // cout << static_cast<Day>(count);
        print_day(static_cast<Day>(count), cout);
    }

    return 0;
}
/* END OF MAIN PROGRAM */
void print_day(Day count, ostream &out)
{
    switch (count)
    {
    case Sun:
        cout << "Sunday";
        break;
    case Mon:
        cout << "Monday";
        break;
    case Tue:
        cout << "Tuesday";
        break;
    case Wed:
        cout << "Wednesday";
        break;
    case Thu:
        cout << "Thursday";
        break;
    case Fri:
        cout << "Friday";
        break;
    case Sat:
        cout << "Saturday";
        break;
    default:
        cout << "ERROR!";
    }
    cout << closing_time(static_cast<Day>(count)) << "pm\n";
}

/* FUNCTION TO GENERATE SHOP CLOSING TIMES FROM DAY OF THE WEEK */
int closing_time(Day day_of_the_week)
{
    switch (day_of_the_week)
    {
    case Sun:
        return 1;
    case Wed:
        return 8;
    case Sat:
        return 5;
    default:
        return 6;
    }
}