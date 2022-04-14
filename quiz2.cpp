/*
         Name: Martin Molina
   Assignment: quiz2
         Date: 3/24/2022
  Description: Write a program that outputs the the distance
               a ball travels until it stops bouncing.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double b, h, h1, dist = 0;

    do
    {
        cout << "The Initial height of a ball (h) must be "
             << "greater than 0" << endl
             << "Enter h: ";
        cin  >> h;
    }   while (h <= 0);

    do
    {
        cout << "The Bounciness ratio (b) must be within "
             << "range 0 < b < 1" << endl
             << "Enter b: ";
        cin  >> b;
    }   while (b < 0 || b >= 1);

    // Ball has to tavel the initial height down
    dist += h;
    h1 = h;
    // Add the height bounced until it's very close to 0
    while (h1 > 0.00001)
    {
        h1 *= b;
        dist += 2 * h1;
    }

    cout << fixed << showpoint << setprecision(4)
         << "h:    " << setw(8) << h << endl
         << "b:    " << setw(8) << b << endl
         << "dist: " << setw(8) << dist << endl;
}

/*  Sample Execution

The Initial height of a ball (h) must be greater than 0
Enter h: 10
The Bounciness ratio (b) must be within range 0 < b < 1
Enter b: 0.75
h:     10.0000
b:      0.7500
dist:  70.0000
*/