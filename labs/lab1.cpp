#include <iostream>
using namespace std;
/*
         Name: Martin Molina
   Assignment: lab1
         Date: 1/31/2022
  Description: Write a program that inputs 3 integer values and outputs the average of the numbers entered
*/

int main()
{
    int num1, num2, num3;

    cout << "Enter 3 integers to calculate the average: " << endl;
    cin >> num1 >> num2 >> num3;

    cout << "The average between the 3 numbers is: " << double(num1 + num2 + num3) / 3 << endl;

    // success
    return 0;
}