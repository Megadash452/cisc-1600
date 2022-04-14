/*
         Name: Martin Molina
   Assignment: lab1
         Date: 2/7/2022
  Description: passing by reference
*/
#include <iostream>
#include <iomanip>

void enter_xy(double& x, double& y);
void print_xy(double x, double y);
void swap_1(double& x, double& y);
void swap_2(double& x, double& y);
void swap_3(double& x, double& y);
// to make these work you need to pass all of them by reference (add the &)

using namespace std;

int main()
{
    double x, y, x_org, y_org;

    cout << endl;
    enter_xy(x_org, y_org);

    cout << "initial values: " << endl;
    x = x_org;
    y = y_org;
    print_xy(x, y);
    cout << endl;

    cout << "== before swap_1: ==" << endl;
    x = x_org;
    y = y_org;
    print_xy(x, y);
    swap_1(x, y);
    cout << "== after swap_1: ==" << endl;
    print_xy(x, y);
    cout << endl;

    cout << "== before swap_2: ==" << endl;
    x = x_org;
    y = y_org;
    print_xy(x, y);
    swap_2(x, y);
    cout << "== after swap_2: ==" << endl;
    print_xy(x, y);
    cout << endl;

    cout << "== before swap_3: ==" << endl;
    x = x_org;
    y = y_org;
    print_xy(x, y);
    swap_3(x, y);
    cout << "== after swap_3: ==" << endl;
    print_xy(x, y);
    cout << endl;

    return 0;
}

void enter_xy(double& x, double& y)
{
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
}

void print_xy(double x, double y)
{
    cout << fixed << showpoint << setprecision(2);
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
}

void swap_1(double& x, double& y)
{
    double temp;

    cout << "...beginning of swap_1..." << endl;
    print_xy(x, y);

    temp = x;
    x = y;
    y = temp;

    cout << "   ...end of swap_1...   " << endl;
    print_xy(x, y);
}

void swap_2(double& x, double& y)
{
    double temp;

    cout << "...beginning of swap_2..." << endl;
    print_xy(x, y);

    temp = x;
    x = y;
    y = temp;

    cout << "   ...end of swap_2...   " << endl;
    print_xy(x, y);
}

void swap_3(double& x, double& y)
{
    double temp;

    cout << "...beginning of swap_1..." << endl;
    print_xy(x, y);

    temp = x;
    x = y;
    y = temp;

    cout << "   ...end of swap_1...   " << endl;
    print_xy(x, y);
}