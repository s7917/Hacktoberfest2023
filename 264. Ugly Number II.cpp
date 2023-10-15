class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0]=1;
        int x=0, y=0, z=0;
        for(int i=1; i<n; i++){
            dp[i] = min(dp[x]*2, min(dp[y]*3, dp[z]*5));
            if(dp[i] == 2*dp[x]) x++;
            if(dp[i] == 3*dp[y]) y++;
            if(dp[i] == 5*dp[z]) z++;
        }
        return dp[n-1];
    }
};