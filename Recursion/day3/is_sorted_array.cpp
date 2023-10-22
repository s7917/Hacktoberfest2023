#include<bits/stdc++.h>
using namespace std;
bool is_sorted(int *arr, int size){
    if(size==0 || size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans= is_sorted(arr+1,size-1);
        return ans;
    }
}
int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    bool result = is_sorted(arr,size);

    if(result){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted"<<endl;
    }

    

    

    return 0;
}