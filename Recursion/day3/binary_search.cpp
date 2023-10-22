#include<bits/stdc++.h>
using namespace std;
bool binary_search(int arr[], int n, int s, int e, int k){
    if(s>=e){
        return false;
    }
    int mid=(s+(e-s))/2;

    if(arr[mid]==k){
        return true;
    }
    if(arr[mid]<k){
        return binary_search(arr,n,mid+1,e,k);
    }
    else{
        return binary_search(arr,n,s,mid-1,k);
    }
}
int main(){
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bool result = binary_search(arr,n,0,n-1,k);    

    if(result){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }
    return 0;
}