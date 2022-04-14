/*
         Name: Martin Molina
   Assignment: hw4
         Date: 3/10/2022
  Description: Write a program that computes sqrt(x) according
               to the Newton's formula.
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double newton_formula(double prev, double x);
double newton_sqrt(double x);

using namespace std;

int main()
{
    double x;

    cout << "Enter a real number: ";
    cin >> x;

    cout << fixed << showpoint << setprecision(4)
         << "Newton Sqrt: " << newton_sqrt(x) << endl;

    return 0;
}


double newton_formula(double prev, double x)
{
    return (prev + x / prev) / 2;
}

double newton_sqrt(double x)
{
    double next, prev = 1;

    next = newton_formula(prev, x);
    while (abs(next - prev) >= 0.005)
    {
        prev = next;
        next = newton_formula(prev, x);
    }

    return next;
}

/*  Sample Execution

Enter a real number: 5
Newton Sqrt: 2.2361
*/