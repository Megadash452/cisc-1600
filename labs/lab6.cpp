/*
         Name: Martin Molina
   Assignment: lab6
         Date: 3/7/2022
  Description: Write a program that accepts from the keyboard
               2 sides of a triangle, and randomly generates
               side c of the triangle
*/
#include <iostream>
#include <iomanip>
#include <ctime>

unsigned int seed = time(0);

double random(unsigned int& seed);

using namespace std;

int main()
{
    double a, b, c = 0;

    cout << "Enter two sides of a triangle (less than 20): ";
    cout << fixed << showpoint << setprecision(4);
    cin >> a >> b;

    // generate random c until the sides can make a triangle
    while (a + b <= c || a + c <= b || b + c <= a)
        c = 25 * random(seed);

    cout << "a = " << setw(8) << a << endl;
    cout << "b = " << setw(8) << b << endl;
    cout << "c = " << setw(8) << c << endl;

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

/*
Enter two sides of a triangle (less than 20)
a: 15.555
b: 16.777
c = 1.9128
*/