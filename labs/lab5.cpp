/*
         Name: Martin Molina
   Assignment: lab5
         Date: 2/28/2022
  Description: Write a program that asks the user to enter 10
               characters from the keyboard and outputs the
               number of A's (not case-sensitive)
*/
#include <iostream>

using namespace std;

int main()
{
    unsigned int num_of_a = 0;
    char input;

    for (int i = 0; i < 10; ++i)
    {
        cout << "Enter a character: ";
        cin >> input;

        if (input == 'a' || input == 'A')
            ++num_of_a;
    }

    cout << "You entered " << num_of_a << " A's (not case-sensitive)"
         << endl;

    return 0;
}

/* Sample Execution

Enter a character: a
Enter a character: b
Enter a character: a
Enter a character: c
Enter a character: a
Enter a character: d
Enter a character: a
Enter a character: e
Enter a character: a
Enter a character: f
You entered 5 A's (not case-sensitive)

*/