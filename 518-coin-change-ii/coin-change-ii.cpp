class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        
          for (int T = 0; T <= amount; ++T) {
            dp[0][T] = (T % coins[0] == 0) ? 1 : 0;
        }

        for(int i=1;i<n;++i){
            for(int j=0;j<=amount;++j){
                long notTake = dp[i-1][j];
                long take = 0;
                if(coins[i]<= j) take = dp[i][j-coins[i]];
                 dp[i][j] = take + notTake ;
            }
        }
        return dp[n-1][amount];
    }
};