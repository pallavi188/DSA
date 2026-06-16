class Solution {
public:
    int f(int i,int k,vector<vector<int>>& piles,vector<vector<int>>&dp){
        int n = piles.size();
        if(i >= n) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int not_taken = f(i+1,k,piles,dp);
        int taken = 0;
        int sum =0;
        //taken has multiple case
        for(int j=0;j<min(k,(int)piles[i].size());j++){
            sum += piles[i][j];
            taken = max(taken,sum + f(i+1,k-(j+1),piles,dp));
        }
        return dp[i][k] = max(taken,not_taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        for(int i = n-1;i>=0;i--){
            for(int l=1;l<=k;l++){
                int not_taken = dp[i+1][l];
                int taken =0;
                int sum =0;
                for(int j=0;j<min(l,(int)piles[i].size());j++){
                    sum += piles[i][j];
                    taken = max(taken , sum + dp[i+1][l-(j+1)]);
                }
                dp[i][l] = max(taken,not_taken);
            }
        }
        return dp[0][k];
    }
};