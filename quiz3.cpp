/*
         Name: Martin Molina
   Assignment: quiz3
         Date: 4/21/2022
  Description: Write a program that determines if all the
               elements in an array are distinct or not
*/
#include <iostream>
#include <iomanip>
#include <ctime>

const int SIZE = 10;
unsigned int seed = time(0);

void initialize_array(int arr[]);
void print_array(const int arr[]);
bool distinct_elements(const int arr[]);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int a[SIZE];

    initialize_array(a);
    print_array(a);

    if (distinct_elements(a))
        cout << "All array elements are distinct.";
    else
        cout << "There are duplicate elements in the array.";
    cout << endl;

    return 0;
}

void initialize_array(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = int(10 + 21 * random(seed));
}

void print_array(const int arr[])
{
    cout << '[';
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << ']' << endl;
}

bool distinct_elements(const int arr[])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
            if (arr[i] == arr[j])
                return false;
    return true;
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

[23, 10, 17, 22, 28, 23, 15, 12, 25, 16]
There are duplicate elements in the array.

------------------------------------------

[22, 14, 21, 29, 30, 28, 12, 10, 18, 17]
All array elements are distinct.
*/