#include<bits/stdc++.h>
using namespace std;
int getsum(int *arr, int n){
    int sum=0;
    if(n==1){
        return  arr[0];
    }
    if(n==0){
        return 0;
    }

    sum += arr[0] + getsum(arr+1,n-1);

    return sum;

}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<getsum(arr,n);

    return 0;
}