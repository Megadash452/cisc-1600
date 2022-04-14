/*
         Name: Martin Molina
   Assignment: lab7
         Date: 3/21/2022
  Description: Write a program that given f(x), determines the
               x_left and x_right such that the sign(f(x_left))
               != sign(f(x_right))
*/
#include <iostream>
#include <iomanip>
#include <cmath>

unsigned int seed = time(0);

double f(double x);
double random(unsigned int& seed);
// Generate a random number in range [k, m) based on seed
double random_range(double k, double m);
void generate_x_left_x_right(double& x_left, double& x_right);

using namespace std;

int main()
{
    double x_left, x_right;

    generate_x_left_x_right(x_left, x_right);

    cout << "Random numbers on opposite sides of x-axis of f(x)"
         << endl << fixed << showpoint << setprecision(5)
         << "   x_left: " << setw(9) << x_left << endl
         << "  x_right: " << setw(9) << x_right << endl;

    return 0;
}


double f(double x)
{
    return pow(x, 3) + pow(5 * x, 2) + 7 * x + 2;
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

double random_range(double k, double m)
{
    return k + (m - k) * random(seed);
}

void generate_x_left_x_right(double& x_left, double& x_right)
{
    double f_x_left;

    x_left = random_range(-100, 100);
    f_x_left = f(x_left);

    do
        x_right = random_range(-100, 100);
    while (f_x_left * f(x_right) > 0);
    // while signs are the same
}

/*  Sample Execution

Random numbers on opposite sides of x-axis of f(x)
   x_left: -36.84678
  x_right:  29.49394
*/