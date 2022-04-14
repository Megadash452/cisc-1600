/*
         Name: Martin Molina
   Assignment: hw6
         Date: 3/21/2022
  Description: Write a program that outputs a root of a given
               function f(x) by using a bisection method
*/
#include <iostream>
#include <iomanip>
#include <cmath>

#define dbg_print(x) std::cout << x << std::endl

unsigned int seed = time(0);

double f(double x);
double random(unsigned int& seed);
// Generate a random number in range [k, m) based on seed
double random_range(double k, double m);
void generate_x_left_x_right(double& x_left, double& x_right);

using namespace std;

int main()
{
    double x_left, x_mid, x_right;

    generate_x_left_x_right(x_left, x_right);

    do
    {
        x_mid = (x_left + x_right) / 2;

        if (f(x_mid) * f(x_right) > 0)
            x_right = x_mid;
        else
            x_left = x_mid;
    }   while(abs(f(x_mid)) > 0.00001);

    cout << fixed << showpoint << setprecision(5)
         << "A root of f(x) is: " << x_mid << endl;
}

double f(double x)
{
    return pow(x, 3) + 5 * pow(x, 2) + 7 * x + 2;
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

A root of f(x) is: -2.61803
*/