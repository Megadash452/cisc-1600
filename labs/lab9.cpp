/*
         Name: Martin Molina
   Assignment: lab9
         Date: 4/4/2022
  Description: Write a program that declares 3 arrays of types
               int, char and double with size 10. Write functions
               fill_array to pupulate each array type. Write a
               function print_array to output each array.
*/
#include <iostream>
#include <iomanip>
#include <ctime>

unsigned int seed = time(0);
const int SIZE = 10;

void fill_array(int arr[]);
void fill_array(char arr[]);
void fill_array(double arr[]);
void print_arrays(int a[], char c[], double d[]);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int int_arr[SIZE];
    char char_arr[SIZE];
    double dbl_arr[SIZE];

    fill_array(int_arr);
    fill_array(char_arr);
    fill_array(dbl_arr);

    print_arrays(int_arr, char_arr, dbl_arr);

    return 0;
}

void fill_array(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = int(11 * random(seed));
}

void fill_array(char arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = char(int('a' + 26 * random(seed)));
}

void fill_array(double arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = 10 * random(seed);
}

void print_arrays(int a[], char c[], double d[])
{
    cout << fixed << showpoint << setprecision(2)
         << "integer | character | double" << endl;
    for (int i = 0; i < SIZE; i++)
        cout << setw(4) << a[i] << "      "
             << setw(5) << c[i] << "       "
             << setw(5) << d[i] << endl;
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

integer | character | double
   5          s        7.99
   8          f        7.68
   2          m        2.75
   7          j        0.13
  10          f        5.08
   0          h        2.80
   7          p        1.62
  10          d        3.95
   9          k        8.91
   4          k        9.05
*/