/*
         Name: Martin Molina
   Assignment: lab12
         Date: 5/2/2022
  Description: Write a program that declares a 2-Dimensional
               array of size [10x10], and initialize the array
               with 0's on the main diagonal, positive random
               ints in range [0, 5) above the main diagonal,
               and negative random ints in range [-5, -10)
               below the main diagonal.
*/
#include <iostream>
#include <iomanip>
#include <ctime>

const int ROW_SIZE = 10;
const int COL_SIZE = 10;
unsigned int seed = time(0);

void fill_2d_array(int arr[][COL_SIZE]);
void print_2d_array(const int arr[][COL_SIZE]);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int a[ROW_SIZE][COL_SIZE];
    fill_2d_array(a);
    print_2d_array(a);

    return 0;
}

void fill_2d_array(int arr[][COL_SIZE])
{
    // use for loop because we iterate through every element
    for (int row = 0; row < ROW_SIZE; row++)
        for (int col = 0; col < COL_SIZE; col++)
            if (row < col)
                arr[row][col] = int(5 * random(seed)); // 0 <= x < 5
            else
                if (row > col)
                    arr[row][col] = int(-10 + 5 * random(seed)); // -10 < x <= -5
                else // row == col
                    arr[row][col] = 0;
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

[ 0  4  3  3  3  4  0  4  0  2 ]
[-7  0  1  3  4  1  4  3  2  4 ]
[-6 -9  0  1  0  4  3  0  2  1 ]
[-6 -8 -8  0  4  1  3  1  2  1 ]
[-6 -9 -6 -6  0  0  1  4  0  4 ]
[-7 -7 -8 -7 -5  0  4  2  3  1 ]
[-5 -6 -6 -9 -9 -8  0  3  2  0 ]
[-9 -8 -7 -9 -5 -8 -5  0  1  4 ]
[-5 -7 -7 -5 -5 -5 -5 -9  0  3 ]
[-7 -6 -9 -7 -8 -9 -7 -9 -8  0 ]
*/