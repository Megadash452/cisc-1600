/*
         Name: Martin Molina
   Assignment: hw3
         Date: 2/28/2022
  Description: Write a program that accpets from the keyboard a
               random point (x_org, y_org) within the unit square,
               generates 10 other random points in the unit
               square, and outputs the point with the furthest
               distance from the point (x_org, y_org)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <assert.h>

double random(unsigned int& seed);
// print a point like this: (x, y). w is the number given to setw()
void print_point(double x, double y, unsigned int w = 0);

using namespace std;

unsigned int seed = 42;


int main()
{
    double x_org, y_org, largest_dist = 0,
           largest_dist_x, largest_dist_y;

    cout << "Enter a point (x, y) with ranges "
         << "0 <= x < 1 and 0 <= y < 1:" << endl;
    cin >> x_org >> y_org;

    cout << fixed << showpoint << setprecision(4);

    // generate 10 points and compare previous distance
    for (int i = 0; i < 10; i++)
    {
        double x = random(seed), y = random(seed);
        double dist_from_org = sqrt(
            pow(x_org - x, 2) + pow(y_org - y, 2)
        );

        if (dist_from_org > largest_dist)
        {
            largest_dist = dist_from_org;
            largest_dist_x = x;
            largest_dist_y = y;
        }
    }

    print_point(largest_dist_x, largest_dist_y, 6);
    cout << " is furthest from ";
    print_point(x_org, y_org, 6);
    cout << endl;
}


double random(unsigned int& seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;

    // result will be < MODULUS
    seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

    // result is < 1
    return double(seed) / MODULUS;

    // 0 <= random(seed) < 1
}

void print_point(double x, double y, unsigned int w)
{
    cout << "(" << setw(w) << x << ", " << setw(w) << y << ")";
}

/* Sample Execution

Enter a point (x, y) with ranges 0 <= x <= 1 and 0 <= y <= 1:
0.3
0.4
(0.9982, 0.8173) is furthest from (0.3000, 0.4000)

*/