class Solution {
public:
    int f(int st,int et,vector<int>&piles,vector<vector<int>>&dp){
        if(st>et) return 0;
        if(dp[st][et] != -1) return dp[st][et];
        return dp[st][et] = max(piles[st]-f(st+1,et,piles,dp),piles[et]-f(st,et-1,piles,dp));

    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,n-1,piles,dp)>0;
    }
};