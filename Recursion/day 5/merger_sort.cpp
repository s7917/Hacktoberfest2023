#include<bits/stdc++.h>
using namespace std;
void merge(int *arr, int s, int e){
    int mid=(s+e)/2;

    int n1 = mid - s + 1;
    int n2 = e - mid;

    int a1[n1];
    int a2[n2];

    int k=s;
    for(int i=0;i<n1;i++){
        a1[i]=arr[k++];
    }
    
    k=mid+1;
    for(int i=0;i<n2;i++){
        a2[i]=arr[k++];
    }

    int i=0,j=0;
    k=s;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[s++]=a1[i++];
        }
        else{
            arr[s++]=a2[j++];
        }
    }
    while(i<n1){
        arr[s++]=a1[i++];
    }
    while(j<n2){
        arr[s++]=a2[j++];
    }
}
void mergesort(int *arr,int s ,int e){
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    
    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=0;
    int e=n-1;

    mergesort(arr,s,e);

     for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

    return 0;

}