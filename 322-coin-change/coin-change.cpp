class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount + 1,0));
        //base case
        for(int amt=0;amt<=amount;amt++){
            if(amt % coins[0] == 0)dp[0][amt] = amt/coins[0];
            else 
            dp[0][amt]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int a=0;a<=amount;a++){
                int pick = 1e9;
                int not_pick = dp[i-1][a];
                if(coins[i] <= a){
                    pick = 1 + dp[i][a - coins[i]];
                   
                }
                 dp[i][a] = min(pick,not_pick);
            }
        }
        if(dp[n-1][amount] == 1e9)return -1;
        else 
        return dp[n-1][amount];
    }
};