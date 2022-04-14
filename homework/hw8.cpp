/*
         Name: Martin Molina
   Assignment: hw8
         Date: 3/31/2022
  Description: Declare and populate an array with 150 lowercase
               characters, and print the array in the form of a
               matrix using only one loop
*/
#include <iostream>
#include <iomanip>
#include <ctime>

unsigned int seed = time(0);
const int SIZE = 150;

double random(unsigned int& seed);

using namespace std;

int main()
{
    char arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = char(int('a' + 26 * random(seed)));

        cout << arr[i] << " ";

        if (!((i+1) % 12))
            cout << endl;
    }

    cout << endl;

    return 0;
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

f a e n w c g r n u m q 
f p x d g q t y b x a t 
q y b u n p n i e l s s 
l b j g h q y g b r n k 
c v g v k k f b m h f d 
z m d q h o d i p z d k 
g k f v l g x i w j v n 
f a y n q p b l e p l y 
q b c r f u c n j c u l 
z u n m y k y g m y z v 
j z w b k y m p u e b f 
h a k q r n q c c t a q 
t k c f w t 
*/