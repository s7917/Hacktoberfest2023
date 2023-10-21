#include <bits/stdc++.h>
using namespace std;
 
long long m,d;
string a,b;
string str;
const long long M = 2007;
long long dp[M][2][2][2][M];
long long mod = 1e9+7;

// make as more variables in state so that there are less chances of overlapping dp

long long solve(long long pos,long long t,long long e,long long st,long long mo){
      if(pos==str.size()){
         return (mo==0);
      }

      if(dp[pos][t][e][st][mo]!=-1){
         return dp[pos][t][e][st][mo];
      }

      long long en = t?(str[pos]-'0'):9;
      long long re = 0;
      
      if(st){
        if(e){
            re+=(solve(pos+1,t&(d==en),e^1,1,(mo*10+d)%m))%mod;
        }else{
            for(long long i=0;i<=en;i++){
               if(i!=d){
                  re+=(solve(pos+1,t&(i==en),e^1,1,(mo*10+i)%m))%mod;
               }else{

               }
            }
        }

        // for(int i=0;i<=en;i++){
        //     if(e and i==d){
        //         re=(re+solve(pos+1,t&(i==en),e^1,1,(mo*10+d)%m))%mod;
        //     }else if(!e and i!=d){
        //         re= (re+solve(pos+1,t&(i==en),e^1,1,(mo*10+i)%m))%mod;
        //     }
        // }

      }else{
            
         re = (re + solve(pos+1,t&(str[pos]=='0'),0,st,mo))%mod;

         for(long long i=1;i<=en;i++){
               if(i!=d){
                  re = (re+solve(pos+1,t&(i==en),1,1,(mo*10+i)%m))%mod;
               }
         }
      }

      return dp[pos][t][e][st][mo] =re;

}



void solve(){
    cin>>m>>d;
    cin>>a>>b;
    string s =a;
    reverse(a.begin(),a.end());
    while(a.size()<b.size()){
        a.push_back('0');
    }
    reverse(a.begin(),a.end());
    

    memset(dp,-1,sizeof dp);
    str = b;
    long long ans = solve(0,1,0,0,0);
    str = a;
    memset(dp,-1,sizeof dp);
    ans  = (ans-solve(0,1,0,0,0)+mod)%mod;
    
    bool flag =false;
    int mi=0;
    for(int i=0;i<s.size();i++){
        if(i%2 and s[i]-'0'!=d){
            flag =true;
        }else if(i%2==0 and s[i]-'0'==d){
            flag =true;
        }
        mi = (10*mi+(s[i]-'0'))%m;
    }

    if(mi){
        flag =true;
    }
    if(!flag){
        ans++;
    }
    ans%=mod;

    cout<<ans<<"\n";

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
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
    
}