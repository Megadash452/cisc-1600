/*
         Name: Martin Molina
   Assignment: hw5
         Date: 3/10/2022
  Description: Given the ellipse (x/a)^2 + (y/b)^2 = 1, find
               the sides of the rectangle inscribed in the
               ellipse which has maximum area
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double rect_area(double x, double a, double b);

using namespace std;

int main()
{
    double a, b, x, x_min, x_max, new_area, prev_area = 0;

    cout << "Major and Minor axes (a & b) of an ellipse\n"
         << "Enter a: ";
    cin  >> a;
    cout << "Enter b: ";
    cin  >> b;
    cout << fixed << showpoint << setprecision(5);

    x = a / 2;
    x_min = 0;
    x_max = a;
    new_area = rect_area(x, a, b);

    while (abs(new_area - prev_area) > 0.00001)
    {
        double x_lower = (x + x_min) / 2,
               x_upper = (x + x_max) / 2,
               area_upper = rect_area(x_upper, a, b),
               area_lower = rect_area(x_lower, a, b);

        prev_area = new_area;
        if (area_upper > area_lower)
        {
            x_min = x;
            x = x_upper;
            new_area = area_upper;
        }
        else
        {
            x_max = x;
            x = x_lower;
            new_area = area_lower;
        }
    }

    cout << "Rectangle (Max Area):" << endl
         << "    x: " << setw(8) << 2 * x              << endl
         << "    y: " << setw(8) << new_area / (2 * x) << endl
         << " Area: " << setw(8) << new_area           << endl;

    return 0;
}


double rect_area(double x, double a, double b)
{
    // y = b * sqrt(1 - (x/a)^2)
    // A_rect = 2x2y = 4xy
    return 4 * x * b * sqrt(1 - pow(x/a, 2));
}


/*  Sample Execution

Major and Minor axes (a & b) of an ellipse
Enter a: 4
Enter b: 2
Rectangle (Max Area):
    x:  5.65820
    y:  2.82775
 Area: 16.00000

----------------------------------

Major and Minor axes (a & b) of an ellipse
Enter a: 2
Enter b: 4
Rectangle (Max Area):
    x:  2.82910
    y:  5.65551
 Area: 16.00000

*/