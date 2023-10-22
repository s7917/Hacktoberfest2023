#include<bits/stdc++.h>
using namespace std;
bool linear_search(int arr[], int n, int k){
    if(n==0){
        return false;
    }
    if(arr[0]==k){
        return true;
    }
    else{
        bool ans = linear_search(arr+1,n-1,k);
        return ans; 
    }
}
int main(){
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool result = linear_search(arr,n,k);    

    if(result){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}