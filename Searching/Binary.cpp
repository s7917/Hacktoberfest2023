#include<bits/stdc++.h>
#include<iostream>
using namespace std;

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
