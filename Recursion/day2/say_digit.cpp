#include<bits/stdc++.h>
using namespace std;
void saydigit(int n, string str[]){
    if(n==0){
        return;
    }
    int digit = n%10;
    n=n/10;

    saydigit(n,str);

     cout<<str[digit]<<" ";
}

int main(){
    string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

    int n;
    cin>>n;

    saydigit(n,str);

    return 0;
}