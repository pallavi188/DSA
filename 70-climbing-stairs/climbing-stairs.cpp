class Solution {
public:
    int f(int idx,vector<int>&dp){
        if(idx==0 || idx==1 || idx<2)return 1;
        if(dp[idx] != -1) return dp[idx];
        int pick1 = f(idx-1,dp);
        int pick2 = f(idx-2,dp);
        return dp[idx]=pick1+pick2;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return f(n,dp);
    }
};