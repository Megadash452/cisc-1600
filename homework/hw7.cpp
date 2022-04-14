/*
         Name: Martin Molina
   Assignment: hw7
         Date: 3/28/2022
  Description: Write a program that declares and fills an
               int array of size 10 with random ints each in
               range [0, 20] and outputs all positions in
               the array that contain the maximum number in
               the array.
*/
#include <iostream>
#include <iomanip>
#include <ctime>

const unsigned int SIZE = 10;
unsigned int seed = time(0);

double random(unsigned int& seed);

using namespace std;

int main()
{
    int max_num = 0, arr[SIZE];
    
    cout << "[";

    // populate and print array
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = int(21 * random(seed));

        cout << setw(2) << arr[i];
        if (i < SIZE - 1)
            cout << ", ";

        if (max_num < arr[i])
            max_num = arr[i];
    }

    cout << "]\nIndices containing max_num: ";

    // print indexes that store max_num
    for (int i = 0; i < SIZE; i++)
        if (arr[i] == max_num)
            cout << i << " ";

    cout << endl;

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

[20,  0,  9, 20,  8,  1, 17,  3,  0, 12]
Indices containing max_num: 0 3 
*/