/**
 * This is solution of the question on leetcode 
 * (https://leetcode.com/problems/maximum-subarray/description/)
 * 
 * NOTE: This is of O(n) time complexity. Hence not ideal for large datasets.
 * 
 * @author abhishek14104(https://github.com/Abhishek14104)
*/


#include <iostream>
#include <climits>
using namespace std;

int main(void)
{
    int count;
    cin >> count;

    int nums[count];
    for (int i = 0; i < count; i++)
        cin >> nums[i];

    int currsum[count+1];
    currsum[0] = 0;
    for(int i = 0; i<count; i++) {
        currsum[i+1] = currsum[i] + nums[i];
    }

    int maxSum = INT_MIN;
    for(int i = 1; i <= count; i++)
    {
        int sum = 0;
        for(int j = 0; j < i; j++)
        {
            sum = currsum[i] - currsum[j];
            maxSum = max(maxSum, sum);
        }
    }
    
    cout << "Maximum sum : " << maxSum << endl;
    
}