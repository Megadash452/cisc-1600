/*
         Name: Martin Molina
   Assignment: lab11
         Date: 4/25/2022
  Description: Design and test function digital_root(n), where
               n is a positive integer. The digital root of n
               is the sum of all digits of n, computed for as
               long as the sum is >= 10
*/
#include <iostream>

unsigned int digital_root(unsigned int n);

using namespace std;

int main()
{
    cout << "dr(8)  : " << digital_root(8)   << endl;
    cout << "dr(12) : " << digital_root(12)  << endl;
    cout << "dr(19) : " << digital_root(19)  << endl;
    cout << "dr(267): " << digital_root(267) << endl;

    return 0;
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

/* Sample Execution

dr(8)  : 8
dr(12) : 3
dr(19) : 1
dr(267): 6
*/