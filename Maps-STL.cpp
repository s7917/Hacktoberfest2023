#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int n;
     string name;
    cin>>n;
    map<string ,int> mpp;
    for(int i=0;i<n;i++)
    {
        int ch;
        cin>>ch>>name;
       
        if(ch==1)
        {
            int marks;
           cin>>marks;
           mpp[name]=mpp[name]+marks; 
        }
      if (ch==2)
      {
          mpp.erase(name);
      }
      if(ch==3)
      {
          cout<<mpp[name]<<endl;
      }
    }
    return 0;
}
