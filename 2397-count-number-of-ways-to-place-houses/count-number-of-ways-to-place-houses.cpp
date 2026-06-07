class Solution {
public:
    int mod = 1e9 + 7;
    int f(int idx,vector<int>&dp){
        if(idx < 0)return 1;
        if(idx == 0) return 2;
        if(dp[idx] != -1) return dp[idx];
        int pick =  f(idx-2,dp);
        int not_pick = f(idx-1,dp);
        
        return dp[idx] = (pick + not_pick)%mod;
    }
  
    int countHousePlacements(int n) {
        
        vector<int>dp(n+1,-1);
        long long way = f(n-1,dp);
        return (way * way)%mod;
    }
};