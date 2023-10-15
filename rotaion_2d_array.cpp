//rotating by 90 degree
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
void rotation(vector <vector<int>> &v){
    int b=v.size();
    for(int i=0;i<b;i++){
        for(int j=0;j<=i;j++){
            swap(v[i][j],v[j][i]);
        }
    }
    for(int i=0;i<b;i++){
        reverse(v[i].begin(),v[i].end());
    }
}
int main(){
    int r,c;
    cout<<"enter the rows : ";
    cin>>r;
    cout<<"enter the coloumn : ";
    cin>>c;
    vector <vector<int>> a(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"enter the element : ";
            cin>>a[i][j];
        }
    }
    cout<<"the array is : "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    rotation(a);
    cout<<"the required array is : "<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}