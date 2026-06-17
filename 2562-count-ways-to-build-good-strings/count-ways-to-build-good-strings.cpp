class Solution {
public:
    int mod = 1e9+7;
    int f(int i,int low, int high, int zero, int one,vector<int>&dp){
        if(i>high) return 0;
        bool addOne = false;
        if(i>=low && i<=high){
            addOne = true;
        }
        if(dp[i] != -1) return dp[i];
        //append 0
        int append0 = f(i+zero,low,high,zero,one,dp);
        int append1 = f(i+one,low,high,zero,one,dp);
        return dp[i] = (addOne + append0 + append1)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return f(0,low,high,zero,one,dp);
    }
};