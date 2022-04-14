/*
         Name: Martin Molina
   Assignment: lab10
         Date: 4/11/2022
  Description: Write a program that uses function fill_array(a)
               to assign unique random integers to the array
*/
#include <iostream>
#include <iomanip>
#include <ctime>

const int SIZE = 10;
const int RANGE = SIZE + 1;
unsigned int seed = time(0);

void fill_array(int a[]);
void print_array(const int a[]);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int a[SIZE];

    fill_array(a);
    print_array(a);

    return 0;
}

void fill_array(int a[])
{
    int i, rand, available_pos = 0;
    bool found;

    while (available_pos < SIZE)
    {
        found = false;
        rand = int(RANGE * random(seed));

        i = 0;
        while (i < available_pos && !found)
        {
            if (a[i] == rand)
                found = true;
            i++;
        }
    
        if (!found)
        {
            a[available_pos] = rand;
            available_pos++;
        }
    }
}

void print_array(const int a[])
{
    cout << '[';
    for (int i = 0; i < SIZE; i++)
    {
        cout << a[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << ']' << endl;
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

[7, 10, 8, 1, 6, 5, 3, 9, 4, 2]
*/