class Solution {
public:
    int mod = 1e9+7;
    int f(int n,int k,int target,vector<vector<int>>&dp){
        if(target < 0) return 0;
        if(n == 0) return target ==0;
        if(dp[n][target] != -1) return dp[n][target];
        int ways = 0;
        for(int face = 1;face <= k;face++){
            ways = (ways + f(n-1,k,target - face,dp))%mod;
        }
        return dp[n][target]= ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return f(n,k,target,dp);
    }
};