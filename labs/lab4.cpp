/*
         Name: Martin Molina
   Assignment: lab4
         Date: 2/22/2022
  Description: Write a program that uses fn random(seed) to compute
               the value of pi
*/
#include <iostream>
#include <iomanip>
#include <cmath>

double random(unsigned int& seed);

unsigned int seed = 21;
// The total number of random points that will be generated
const unsigned int TOTAL = 99999999;

using namespace std;

int main()
{
    // Number of points that fall within the unit circle
    unsigned int n_c = 0;
    double x, y;

    for (unsigned int i = 0; i <= TOTAL; ++i)
    {
        // Generate random points within unit square
        x = random(seed);
        y = random(seed);

        // distance from any point in unit circle is always < 1
        if (sqrt(x*x + y*y) <= 1)
            ++n_c;
    }

    cout << fixed << showpoint << setprecision(10)
         << "pi = " << 4.0 * n_c / TOTAL << endl;

    return 0;
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

/* Sample Execution

pi = 3.1490983515

*/