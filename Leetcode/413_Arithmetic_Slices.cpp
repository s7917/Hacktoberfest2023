class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<=2){
            return 0;
        }
        vector<int>dp(nums.size(),0);
        for(int i=2;i<nums.size();i++){
            if(nums[i]+nums[i-2]==2*nums[i-1])dp[i]=dp[i-1]+1;
        }
        return accumulate(dp.begin(),dp.end(),0);
    }
};
