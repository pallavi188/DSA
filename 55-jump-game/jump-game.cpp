class Solution {
public:
    bool f(int idx,vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        if(idx >= n-1)return true;
        if(dp[idx] != -1)return dp[idx];
        int maxIdx = min(n-1,idx+nums[idx]);
        for(int i=idx+1;i<=maxIdx;i++){
            if(f(i,nums,dp)){
                dp[idx]=1;
                return true;
            }    
        }
        dp[idx] = 0;
        return false;
    }
    bool canJump(vector<int>& nums) {
         int n = nums.size();
         vector<int>dp(n,-1);
         return f(0,nums,dp);
    }
};