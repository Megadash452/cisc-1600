/*
         Name: Martin Molina
   Assignment: final
         Date: 5/9/2022
  Description: Declare an array of size 15 with random ints in
               range [1, r], where r is a constant int > 1, and
               print the position of all the pairs in the array
               that add up to an integer pair_sum given by the
               user
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <assert.h>

const int SIZE = 15;
const int R = 10;
unsigned int seed = time(0);

void fill_array(int arr[]);
void print_array(const int arr[]);
int input_pair_sum();
void print_pos_of_pairs(const int arr[], int pair_sum);
double random(unsigned int& seed);

using namespace std;

int main()
{
    int a[SIZE], pair_sum = input_pair_sum();

    fill_array(a);

    cout << endl << "Array: " << endl;
    print_array(a);

    cout << endl << "Positions of pairs for which sum is "
         << R << ": " << endl;
    print_pos_of_pairs(a, pair_sum);

    return 0;
}

void fill_array(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        // 1 <= x <= r {r = 10}
        arr[i] = int(1 + R * random(seed));
}

void print_array(const int arr[])
{
    cout << "[";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int input_pair_sum()
{
    int pair_sum;

    assert(R > 1);

    do
    {
        cout << "Enter pair_sum. Value must be between 1 and "
             << R << ": ";
        cin >> pair_sum;
    }   while (pair_sum < 1 || pair_sum > R);

    return pair_sum;
}

void print_pos_of_pairs(const int arr[], int pair_sum)
{
    cout << "    pos-1  pos-2" << endl;

    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
            if (arr[i] + arr[j] == pair_sum)
                cout << setw(7) << i << setw(7) << j << endl;
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

Enter pair_sum. Value must be between 1 and 10: 10

Array: 
[7, 2, 10, 6, 9, 10, 1, 3, 7, 3, 9, 9, 9, 1, 10]

Positions of pairs for which sum is 10: 
    pos-1  pos-2
      0      7
      0      9
      4      6
      4     13
      6     10
      6     11
      6     12
      7      8
      8      9
     10     13
     11     13
     12     13
*/