/*
         Name: Martin Molina
   Assignment: hw10
         Date: 4/25/2022
  Description: Design and test function digital_root(n), where
               n is a positive integer. The digital root of n
               is the sum of all digits of n, computed for as
               long as the sum is >= 10
*/
#include <iostream>
#include <iomanip>

const int ROW_SIZE = 9;
const int COL_SIZE = 9;

void fill_2d_array(int arr[][COL_SIZE]);
void print_2d_array(const int arr[][COL_SIZE]);
unsigned int digital_root(unsigned int n);

using namespace std;

int main()
{
    int a[ROW_SIZE][COL_SIZE];

    fill_2d_array(a);
    cout << "Original array: " << endl;
    print_2d_array(a);
    cout << endl;

    for (int row = 0; row < ROW_SIZE; row++)
        for (int col = 0; col < COL_SIZE; col++)
            a[row][col] = digital_root(a[row][col]);

    cout << "Digital Root array: " << endl;
    print_2d_array(a);

    return 0;
}

void fill_2d_array(int arr[][COL_SIZE])
{
    for (int row = 0; row < ROW_SIZE; row++)
        for (int col = 0; col < COL_SIZE; col++)
            arr[row][col] = (row + 1) * (col + 1);
}

void print_2d_array(const int arr[][COL_SIZE])
{
    for (int row = 0; row < ROW_SIZE; row++)
    {
        cout << "[";
        for (int col = 0; col < COL_SIZE; col++)
            cout << setw(2) << arr[row][col] << " ";
        cout << "]" << endl;
    }
}

unsigned int digital_root(unsigned int n)
{
    unsigned int sum = 0;

    do
    {
        sum = 0;
        while (n > 0)
        {
            sum += n % 10;
            n /= 10;
        }
        n = sum;
    }   while (n >= 10);

    return n;
}

/* Observation

All numbers that are products of 9 will have a digital root of 9.
Because the digits in products of 9 (except 99) will add up to 9.
For products < 100, the 1's digit incremented by 1 and the 10's
digit decrementing by 1.
And then after that dr(99)  = dr(18) = 9
                    dr(108) = dr(9)  = 9
                    dr(117) = dr(9)  = 9
                    etc...
*/


/* Sample Execution

Original array: 
[ 1  2  3  4  5  6  7  8  9 ]
[ 2  4  6  8 10 12 14 16 18 ]
[ 3  6  9 12 15 18 21 24 27 ]
[ 4  8 12 16 20 24 28 32 36 ]
[ 5 10 15 20 25 30 35 40 45 ]
[ 6 12 18 24 30 36 42 48 54 ]
[ 7 14 21 28 35 42 49 56 63 ]
[ 8 16 24 32 40 48 56 64 72 ]
[ 9 18 27 36 45 54 63 72 81 ]

Digital Root array: 
[ 1  2  3  4  5  6  7  8  9 ]
[ 2  4  6  8  1  3  5  7  9 ]
[ 3  6  9  3  6  9  3  6  9 ]
[ 4  8  3  7  2  6  1  5  9 ]
[ 5  1  6  2  7  3  8  4  9 ]
[ 6  3  9  6  3  9  6  3  9 ]
[ 7  5  3  1  8  6  4  2  9 ]
[ 8  7  6  5  4  3  2  1  9 ]
[ 9  9  9  9  9  9  9  9  9 ]
*/