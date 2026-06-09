class Solution {
public:
    int f(int idx,int p,vector<int>&nums,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx>=n) return 0;
         if(dp[idx][p+1]!=-1)return dp[idx][p+1];
        int take =0;
        if(p ==-1 || nums[idx]>nums[p])
        take = 1+ f(idx+1,idx,nums,dp);
        int not_take = f(idx+1,p,nums,dp);
        return dp[idx][p+1] =  max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};