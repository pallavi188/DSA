class Solution {
public:
    int cntSubset(int idx,vector<int>&nums,int reqSum,vector<vector<int>>&dp){
        int n = nums.size();
        if(idx>=n)return reqSum == 0;
        if(reqSum < 0)return 0;
        if(dp[idx][reqSum] != -1) return dp[idx][reqSum];
        int pick = cntSubset(idx+1,nums,reqSum - nums[idx],dp);
        int not_pick = cntSubset(idx+1,nums,reqSum,dp);
        return dp[idx][reqSum] = (pick + not_pick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
       
        for(int i=0;i<n;i++)totalSum += nums[i];
        if(abs(target) > totalSum)return 0;
        if((totalSum+target)%2 != 0)return 0;
        int reqSum = (totalSum + target)/2;
         vector<vector<int>>dp(n+1,vector<int>(reqSum+1,-1));
        return cntSubset(0,nums,reqSum,dp);
    }
};