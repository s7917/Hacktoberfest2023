#include<bits/stdc++.h>
using namespace std;
int merge(int *arr, int start, int end){
    int mid=(start+end)/2;
    
    int len1=mid-start+1;
    int len2=end-mid;

    int a1[len1];
    int a2[len2];

    int k=start;
    for(int i=0;i<len1;i++){
        a1[i]=arr[k++];
    }

    k=mid+1;
    for(int i=0;i<len2;i++){
        a2[i]=arr[k++];
    }

    int i=0,j=0,count=0;
    k=start;

    while(i<=len1 && j<len2){
        if(a1[i]<a2[j]){ 
            arr[k++]=a1[i++];
        }
        else{
            arr[k++]=a2[j++];
            count+=mid-i;
        }
    }
    while(i<len1){
        arr[k++]=a1[i++];
    }
    while(j<len2){
        arr[k++]=a2[j++];
    }
    return count;
}
int count_inversion(int *arr, int s, int e){
    int count=0;

    if(s>=e){
       return count;
    }
    int mid=(s+e)/2;

    count += count_inversion(arr,s,mid);

    count += count_inversion(arr,mid+1,e);

    count += merge(arr,s,e);

    return count;
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
    int count=0;

    cout<<count_inversion(arr,s,e);


    return 0;
}