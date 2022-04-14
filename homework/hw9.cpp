/*
         Name: Martin Molina
   Assignment: hw9
         Date: 4/7/2022
  Description: Write a function partition(f, l, p, a) which
               partitions array (a) into 2 parts (left & right).
               Elements < p should be on the left, and elements
               >= p should be on the right. f should be set to
               the first element of a portion of the array to be
               partitioned, and l is the last element of the
               array to be subjected to the partition.
*/
#include <iostream>
#include <iomanip>
#include <ctime>

unsigned int seed = time(0);
const int SIZE = 10;

void fill_array(int a[]);
void print_array(int a[]);
void partition(int first, int last, int pivot, int arr[]);
double random(unsigned int& seed);
void swap(int &a, int &b);

using namespace std;

int main()
{
    int a[SIZE], f, l, p;

    fill_array(a);

    cout << "Original Array: " << endl;
    print_array(a);

    p = int((SIZE + 1) * random(seed));
    // f is at least 1 less than last index
    f = int((SIZE - 1) * random(seed));
    // l must be larger than f
    do
        l = int(SIZE * random(seed));
    while (l <= f);
    
    cout << "first: " << setw(3) << f << endl
         << " last: " << setw(3) << l << endl
         << "pivot: " << setw(3) << p << endl;

    partition(f, l, p, a);

    cout << "Partitioned Array: " << endl;
    print_array(a);
}

void fill_array(int a[])
{
    for (int i = 0; i < SIZE; i++)
        a[i] = int((SIZE + 1) * random(seed));
}

void print_array(int a[])
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

void partition(int first, int last, int pivot, int arr[])
{
    while (first < last)
    {
        // find an element that needs to be on the right side
        while (first < last && arr[first] < pivot)
            first++;
        // find an element that needs to be on the left side
        while (last > first && arr[last] >= pivot)
            last--;

        swap(arr[first], arr[last]);
        /* no need to inc/dec f & l because that will be done by the
        inner while loops in the next iteration */
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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}