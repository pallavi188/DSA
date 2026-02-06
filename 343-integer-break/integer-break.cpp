class Solution {
public:
    int f(int n , vector<int>&dp){
        if(n==1)return 1;
        int res =0;
        if(dp[n]!= -1) return dp[n];

        for(int idx=1;idx<n;idx++){
        int notBreak = idx*(n-idx);
        int doBreak = idx*f(n-idx,dp);
        res = max(res,max(notBreak,doBreak));
        }
        return dp[n]=res;
    }
    int integerBreak(int n) {
        int idx = 1;
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};