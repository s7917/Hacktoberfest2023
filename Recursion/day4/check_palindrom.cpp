#include<bits/stdc++.h>
using namespace std;
bool palindrom(string& str, int i, int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return palindrom(str,i+1,j-1);
    }
}
int main(){
    string str;
    cin>>str;

    int n=str.length();
    int i=0;
    int j=n-1;

    bool ans = palindrom(str,i,j);

    if(ans){
        cout<<"palindrom"<<endl;
    }
    else{
        cout<<"not palindrom"<<endl;
    }

    return 0;
}