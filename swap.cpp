#include <iostream>
using namespace std;

int main()
{
    int num1, num2, temp;
    
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    cout << "The first number is " << num1 << endl;
    cout << "The second number is " << num2 << endl;

    temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "The numbers have been swapped" << endl;
    cout << "The first number is " << num1 << endl;
    cout << "The second number is " << num2 << endl;

    return 0;
}