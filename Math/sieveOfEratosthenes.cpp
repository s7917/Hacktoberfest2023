#include <iostream>
using namespace std;

//this is a more efficient way to print the prime numbers upto 'n';

int main(void){
    int n;
    cin >> n;

    
    int arr[n];

    for(int i = 1; i<=n ; i++)
    {
        arr[i-1] = 0;
    }

    for (int i = 2; i*i <= n; i++)
    {
        if (arr[i-1] == 0)
        {
            int j = i*i;
            int c = i+1;
            while(j <= n){
                arr[j-1] = 1;
                j = i*c;
                c++;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
            cout << i+1 << " ";
    }
    cout << endl;
    
    return 0;
}