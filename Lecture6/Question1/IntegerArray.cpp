#include <iostream>
#include "IntegerArray.h"
#include <cmath>
using namespace std;

void input_array(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": " << endl;
        cin >> arr[i];
    }
}

void display_array(int arr[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void copy_array(int arr1[], int arr2[], int n)
{
    for (size_t i = 0; i < n; i++)
    {
        arr1[i] = arr2[i];
    }
}

double standard_deviation(int arr[], int n)
{
    int sum;
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    double avg = sum / n;

    double sum_avg;
    for (size_t i = 0; i < n; i++)
    {
        sum_avg += (arr[i] - avg) * (arr[i] - avg);
    }

    return sqrt(sum_avg / n);
}