#include<bits/stdc++.h>
#include<iostream>
using namespace std;
// 1. first we divide in two parts 
// 2. find the middle part .
// 3. check the target value is greater or less or equal.
// 4. if target is equal = mid then return mid.
// 5. else if target is less then high becomes mid-1 and check furthur.
// 6 . if target greater mid then low = mid+1 and furthur operation are allowed.

int binarysearch(vector<int>&v,int target){
    int l = 0;
    int h = v.size()-1;
    while(l<=h){
    int mid = (l+h)/2;
    if(v[mid]==target) return mid;
    else if(v[mid]<target){
        l=mid+1; 
    }
    else h=mid-1;
    }
    return -1;
}
int main(){
// vector<int>v={2,3,76,34,28,26,18};
// sort(v.begin(),v.end());
// int target ;
// cin>>target;
// cout<<binarysearch(v,target);
// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
// }cout<<endl;
// int n,target;
// cin>>n>>target;
// vector<int>v;
// for(int i=0;i<n;i++){
//     int x;
//     cin>>x;
//     v.push_back(x);
// }
// cout<<binarysearch(v,target);
return 0;
}
