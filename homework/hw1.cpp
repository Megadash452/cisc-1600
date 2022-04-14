/*
         Name: Martin Molina
   Assignment: hw1
         Date: 2/7/2022
  Description: Write a program that uses function formula of x to compute    
               and output the value of (x * x - sqrt(x) + abs(x)) / (2 * x) 
         File: hw2
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double formula(double x);

using namespace std;

int main()
{
    double input;

    cout << "Please enter a zero or positive real number: ";
    cin >> input;

    cout << "The formula gives: " << fixed << setprecision(5);
    cout << formula(input) << endl;

    return 0;
}

double formula(double x)
{
    return (x * x - sqrt(x) + abs(x)) / (2 * x);
}

/*  Sample Execution:
    
    Please enter a zero or positive real number: 4.2
    The formula gives: 2.35602
*/