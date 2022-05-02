/*
         Name: Martin Molina
   Assignment: extra-credit
         Date: 5/2/2022
  Description: 
*/
#include <iostream>

int SIZE = 10;

void r_combination(int r, int arr[]);

using namespace std;

int main()
{

}

void r_combination(int r, int arr[])
{
    bool found = false;

    // Iterate backwards to find _last_ element that meets criteria
    int i = SIZE - 1;
    while (i > 0 && !found)
    {
        // if (n - r + i != arr[i])
        //     found = true;

        i--;
    }

    cout << "i: " << i << endl;
}

