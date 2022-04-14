/*
         Name: Martin Molina
   Assignment: hw2
         Date: 2/11/2022
  Description: Write a program that accepts 3 coefficients of a
               quadratic equation from the keyboard and
               outputs the real roots
         File: hw2.cpp
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double root_1(double a, double b, double c);
double root_2(double a, double b, double c);
double root_1_vietas(double a, double b, double c);
double root_2_vietas(double a, double c, double root_1);
int    sign(double num);

using namespace std;

int main()
{
    double a, b, c;

    cout << "Enter the coefficients for a quadratic equation"
         << "ax^2 + bx + c:" << endl;
    cin >> a >> b >> c;

    if (b*b - 4*a*c < 0) // number inside square root is negative
        cout << "The quadratic equation "
             << a << "x^2 + " << b << "x + " << c
             << " has no real roots" << endl;
    else if (a == 0)     // divide by 0 error
        cout << "The equation "
             << b << "x + " << c
             << " is linear" << endl;
    else 
    {
        cout << "The root for quadratic equation "
             << a << "x^2 + " << b << "x + " << c;

        if (b*b > 20 * 4*a*c) // use Vieta's Method
        {
            double root_1 = root_1_vietas(a, b, c);

            cout << " using Vieta's Method are:" << endl
                 << "root 1: " << root_1 << endl
                 << "root 2: " << root_2_vietas(a, c, root_1);
        }
        else if (b*b - 4*a*c == 0) // quadratic has 1 root
            cout << " is:" << endl
                 << root_1(a, b, c) << endl;
        else // compute the roots normally
            cout << " are:" << endl
                 << "root 1: " << root_1(a, b, c) << endl
                 << "root 2: " << root_2(a, b, c) << endl;
    }
    
    return 0;
}


int main_correct()
{
    double a, b, c;

    cout << "Enter the coefficients for a quadratic equation"
         << "ax^2 + bx + c:" << endl;
    cin >> a >> b >> c;

    if (a == 0)
        cout << "The equation " << b << "x + " << c
             << " is linear" << endl;
    else
    {
        double discriminant = b*b - 4*a*c;

        cout << "The quadratic equation "
             << a << "x^2 + " << b << "x + " << c;

        if (discriminant < 0)
            cout << " has no real roots" << endl;
        else
        {
            double r_1, r_2;

            if (b*b > 20 * 4*a*c)
            {
                r_1 = root_1_vietas(a, b, c);
                r_2 = root_2_vietas(a, c, r_1);
            }
            else
            {
                r_1 = root_1(a, b, c);
                r_2 = root_2(a, b, c);
            }

            cout << " has roots:" << endl
                 << "root 1: " << setw(8) << r_1 << endl
                 << "root 2: " << setw(8) << r_2 << endl;
        }
    }
}


double root_1(double a, double b, double c)
{
    return (-b + sqrt(b*b - 4 * a * c)) / (2 * a);
}

double root_2(double a, double b, double c)
{
    return (-b - sqrt(b*b - 4 * a * c)) / (2 * a);
}

double root_1_vietas(double a, double b, double c)
{
    return (-b - sign(b) * sqrt(b*b - 4 * a * c)) / (2 * a);
}

double root_2_vietas(double a, double c, double root_1)
{
    return c / (a * root_1);
}


int sign(double num)
{
    if (num >= 0)
        return 1;

    return -1;
}


/*  Sample Execution

Enter the coefficients for a quadratic equation ax^2 + bx + c:
3
1
4
The quadratic equation 3x^2 + 1x + 4 has no real roots

---------------------------------------------------------------

Enter the coefficients for a quadratic equation ax^2 + bx + c:
0
2
4
The equation 2x + 4 is linear

---------------------------------------------------------------

Enter the coefficients for a quadratic equation ax^2 + bx + c:
1
999
2
The roots for quadratic equation 1x^2 + 999x + 2 using Vieta's Method are:
root 1: -998.998
root 2: -0.00200201

---------------------------------------------------------------

Enter the coefficients for a quadratic equation ax^2 + bx + c:
1
2
1
The root for quadratic equation 1x^2 + 2x + 1 is:
-1

---------------------------------------------------------------

Enter the coefficients for a quadratic equation ax^2 + bx + c:
2
6
1
The roots for quadratic equation 2x^2 + 6x + 1 are:
root 1: -0.177124
root 2: -2.82288

*/