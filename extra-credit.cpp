/*
         Name: Martin Molina
   Assignment: extra-credit
         Date: 5/2/2022
  Description: List the 3-combinations of { 1, 2, 3, 4, 5 }
               in lexographic order
*/
#include <iostream>
#include <assert.h>

int SIZE = 5;

void fill_array(int arr[]);
void print_array(const int arr[], int size);
void r_combinations(int r, int arr[]);

using namespace std;

int main()
{
    int a[SIZE], r = 3;

    fill_array(a);

    print_array(a, SIZE);
    cout << endl <<  r << "-combinations: " << endl;
    r_combinations(r, a);

    return 0;
}

void fill_array(int arr[])
{
    for (int i = 0; i < SIZE; i++)
        arr[i] = i + 1;
}

void print_array(const int arr[], int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << " }" << endl;
}

void r_combinations(int r, int arr[])
{
    bool done = false, found;
    int i;

    // r cannot be larger than Size
    assert(r <= SIZE);

    while (!done)
    {
        // print r-combination
        print_array(arr, r);

        found = false;

        /* Iterate backwards to find _last_ element that
           meets criteria */
        i = r - 1;
        while (i >= -1 && !found)
        {
            // Step 1:
            // Stop because element does not exist
            if (i < 0)
                done = true;
            else
                // n - r + 1 != a_i; n is last element in array
                if (arr[SIZE - 1] - r + i + 1 != arr[i])
                {
                    // Step 2:
                    arr[i] += 1;
                    // Step 3:
                    for (int j = i + 1; j <= r; j++)
                        arr[j] = arr[j - 1] + 1;
                    found = true;
                }
            i--;
        }
    }
}

/*  Sample Execution

{ 1, 2, 3, 4, 5 }

3-combinations: 
{ 1, 2, 3 }
{ 1, 2, 4 }
{ 1, 2, 5 }
{ 1, 3, 4 }
{ 1, 3, 5 }
{ 1, 4, 5 }
{ 2, 3, 4 }
{ 2, 3, 5 }
{ 2, 4, 5 }
{ 3, 4, 5 }
*/