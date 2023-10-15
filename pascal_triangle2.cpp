#include<iostream>
using namespace std;
#include<vector>
int main(){
    int n;
    cout<<"enter the rows : ";
    cin>>n;
    vector <vector <int> > v(n,vector<int>(n,1));
    for(int i=0;i<n;i++){
        v[i].resize(i+1);
        for(int j=0;j<v[i].size();j++){
            if(j==0 or j==i){
                v[i][j]=1;
            }
            else{
            v[i][j]=v[i-1][j]+v[i-1][j-1];
           }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}