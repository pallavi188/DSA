class Solution {
public:
    int f(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
         if(idx == 0){
            if(amount%coins[0] == 0) return amount/coins[0];
            else 
            return 1e9;
         }
         if(dp[idx][amount] != -1) return dp[idx][amount];
        int take = 1e9;
        int not_take = f(idx-1,amount,coins,dp);
        if(coins[idx] <= amount) take = 1 + f(idx,amount-coins[idx],coins,dp);
        return dp[idx][amount] = min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount + 1,-1));
        int cnt = f(n-1,amount,coins,dp);
        if(cnt == 1e9)return -1;
        else 
        return cnt;
    }
};