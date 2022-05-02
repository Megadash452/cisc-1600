/*
         Name: Martin Molina
   Assignment: hw11
         Date: 4/28/2022
  Description: Write a program that randomly initializes int
               matrices A and B of size 5x5 with random ints
               in range 0 to 5, and use the function
               matrix_multiply on A and B
*/
#include <iostream>
#include <iomanip>
#include <ctime>

unsigned int seed = time(0);
const int SIZE = 5;

void fill_2d_array(int arr[][SIZE]);
void print_2d_array(const int arr[][SIZE]);
void matrix_multiply(const int A[][SIZE], const int B[][SIZE],
                                           int result[][SIZE]);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE];

    fill_2d_array(a);
    fill_2d_array(b);

    cout << "Matrix A: " << endl;
    print_2d_array(a);
    cout << endl << "Matrix B: " << endl;
    print_2d_array(b);

    matrix_multiply(a, b, c);
    cout << endl << "Matrix C: " << endl;
    print_2d_array(c);
}

void fill_2d_array(int arr[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
        for (int col = 0; col < SIZE; col++)
            arr[row][col] = 5 * random(seed);
}

void print_2d_array(const int arr[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        cout << "[";
        for (int col = 0; col < SIZE; col++)
            cout << setw(2) << arr[row][col] << " ";
        cout << "]" << endl;
    }
}

void matrix_multiply(const int A[][SIZE], const int B[][SIZE],
                                           int result[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++)
                result[i][j] += A[i][k] * B[k][j];
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

Matrix A: 
[ 0  0  3  4  4 ]
[ 3  4  3  3  0 ]
[ 1  0  1  4  2 ]
[ 0  2  1  3  0 ]
[ 1  1  4  3  0 ]

Matrix B: 
[ 3  2  4  4  4 ]
[ 4  3  4  3  1 ]
[ 4  4  0  4  3 ]
[ 1  0  0  4  2 ]
[ 2  3  3  4  1 ]

Matrix C: 
[24 24 12 44 21 ]
[40 30 28 48 31 ]
[15 12 10 32 17 ]
[15 10  8 22 11 ]
[26 21  8 35 23 ]
*/