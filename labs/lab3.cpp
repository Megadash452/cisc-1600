/*
         Name: Martin Molina
   Assignment: lab3
         Date: 2/14/2022
  Description: Write a program that accepts 3 values: a, b, c; from the keyboard and outputs either:
                   "values of a = _, b = _, c = _ form a triangle"
                   "values of a = _, b = _, c = _ do not form a triangle"
*/
#include <iostream>
#include <iomanip>

int longest_side(int a, int b, int c);

using namespace std;

int main()
{
    int a, b, c;

    cout << "Enter 3 numbers to check if they can form a triangle:" << endl;
    cin >> a >> b >> c;

    cout << "The numbers entered can";
    if ( !(a + b > c && a + c > b && b + c > a) )
        cout << "not";
    cout << " form a triangle" << endl;

    return 0;
}

/* Sample Execution

Enter 3 numbers to check if they can form a triangle:
3
4
5
The numbers entered can form a triangle

Enter 3 numbers to check if they can form a triangle:
3
2
9
The numbers entered cannot form a triangle

*/