/**
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that 
 * they add up to target.
 * 
 * author [Abhishek14104] (https://github.com/Abhishek14104)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{   
    int nums[10000];
    int a,target, sum, c, d;

    cout<<"The number of digits you want to provide is?" << endl;
    cin>> a;

    cout<< "Enter the target value \n";
    cin>> target;

    for (int i = 0; i <a; i++)
    {
        cout<< "Enter the " << (i+1) << " number"<< endl;
         cin>> nums[i];
    }
    

    for (int j = 0; j < a; j++)
    {
        for (int t = 0; t+j < a ; t++)
        {
                sum = nums[j] + nums[j+t];
                
                if (sum == target)
                {
                    cout<<"The requierd output is ["<< j <<", "<< j+t << "]";
                }
                else;
         }
    }
        


    return 0;
}