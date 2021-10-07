#include "conversions.h"
#include <iostream>
using namespace std;

/* FUNCTION TO CONVERT FAHRENHEIT TO CELSIUS */
double celsius_of(int fahr)
{
    return (static_cast<double>(5) / 9) * (fahr - 32);
}
/* END OF FUNCTION */

/* FUNCTION TO CONVERT FAHRENHEIT TO ABSOLUTE VALUE */
double absolute_value_of(int fahr)
{
    return ((static_cast<double>(5) / 9) * (fahr - 32)) + 273.15;
}
/* END OF FUNCTION */