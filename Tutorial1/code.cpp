#include <iostream>
using namespace std;

const double PI = 3.1415926535;
double calculateCylinderVolume(double radius, double height);
void inputCylinderMeasurements(int cylinderNumber, double &radius, double &height);
void outputCylinderVolume(int cylinderNumber, double volume);

int main()
{

    int cylinders;

    cout << "Enter the number of cylinders: " << endl;
    cin >> cylinders;

    for (int count = 0; count < cylinders; count++)
    {
        double r, h, v;

        inputCylinderMeasurements(count, r, h);
        v = calculateCylinderVolume(r, h);
        outputCylinderVolume(count, v);
    }

    return 0;
}

double calculateCylinderVolume(double radius, double height)
{

    double baseArea, volume;

    if ((radius < 0) || (height < 0))
    {
        cout << "Warning : negative radius or height supplied." << endl;
        return 0;
    }

    baseArea = PI * radius * radius;
    volume = baseArea * height;

    return volume;
}

void inputCylinderMeasurements(int cylinderNumber, double &radius, double &height)
{
    cout << "Enter the radius for cylinder " << cylinderNumber << " : " << endl;
    cin >> radius;
    cout << "Enter the height for cylinder " << cylinderNumber << ":" << endl;
    cin >> height;
}

void outputCylinderVolume(int cylinderNumber, double volume)
{
    cout << "The volume for cylinder " << cylinderNumber << " is" << volume;
    cout << endl;
}