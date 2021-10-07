#include "statistics.h"
#include <iostream>
#include <cmath>
using namespace std;

double average(int num1)
{
    return num1;
}
double average(int num1, int num2)
{
    return (num1 + num2) / 2;
}
double average(int num1, int num2, int num3)
{
    return (num1 + num2 + num3) / 3;
}
double average(int num1, int num2, int num3, int num4)
{
    return (num1 + num2 + num3 + num4) / 4;
}

double standard_deviation(int num1)
{
    double avg = average(num1);
    double sum = (num1 - avg) * (num1 - avg);
    return sqrt(sum / 1);
}
double standard_deviation(int num1, int num2)
{
    double avg = average(num1, num2);
    double sum = (num1 - avg) * (num1 - avg) + (num2 - avg) * (num2 - avg);
    return sqrt(sum / 2);
}
double standard_deviation(int num1, int num2, int num3)
{
    double avg = average(num1, num2, num3);
    double sum = (num1 - avg) * (num1 - avg) + (num2 - avg) * (num2 - avg) + (num3 - avg) * (num3 - avg);
    return sqrt(sum / 3);
}
double standard_deviation(int num1, int num2, int num3, int num4)
{
    double avg = average(num1, num2, num3, num4);
    double sum = (num1 - avg) * (num1 - avg) + (num2 - avg) * (num2 - avg) + (num3 - avg) * (num3 - avg) + (num4 - avg) * (num4 - avg);
    return sqrt(sum / 4);
}
