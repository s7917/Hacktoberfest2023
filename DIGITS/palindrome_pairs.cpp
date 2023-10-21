#include <bits/stdc++.h>
using namespace std;
 

string a,b,str;
long long dp[20][11][11][2][2][2][2]={0};

long long solve(long long pos,long long las,long long slas,long long t,long long st ,long long e,long long o ){
       if(pos==(long long)str.size()){
         return (o and e);
       }

       if(dp[pos][las][slas][t][st][e][o]!=-1){
        return dp[pos][las][slas][t][st][e][o];
       }

       long long en = (t?(str[pos]-'0'):9);
       long long re=0;
       if(!st){
           re+=solve(pos+1,las,slas,t&(str[pos]=='0'),0,0,0);
           for(long long i=1;i<=en;i++){
             re+=solve(pos+1,i,slas,t&(i==en),1,0,0);
           }
       }else{
          for(long long i=0;i<=en;i++){
             re+=solve(pos+1,i,las,t&(i==en),1,e|(i==las),
              ((o|(slas==i))));
          }
       }

       return dp[pos][las][slas][t][st][e][o] = re;

}




void sol(){
    memset(dp,-1,sizeof dp);
    cin>>a>>b;
    str=b;
    long long flag = solve(0,10,10,1,0,0,0);
    memset(dp,-1,sizeof dp);
    str =a ;
    flag -=solve(0,10,10,1,0,0,0);

    cout<<flag<<"\n";

}


int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    long long  t=1;
    cin>>t;
    while(t--){
        sol();
    }
    return 0;
    
}