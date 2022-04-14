/*
         Name: Martin Molina
   Assignment: lab8
         Date: 3/28/2022
  Description: Write a program that declares a char array of
               size 10, and populate it with lowercase random
               letters. Array should be printed 1 char per line
*/
#include <iostream>

unsigned int seed = time(0);
const unsigned int ARR_SIZE = 10;

double random(unsigned int& seed);

using namespace std;

int main()
{
    char a[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++)
    {
        a[i] = char(int('a' + 26 * random(seed)));
        cout << i << ": " << a[i] << endl;
    }

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

/*  Sample Execution

0: m
1: d
2: s
3: a
4: q
5: s
6: r
7: a
8: r
9: o
*/