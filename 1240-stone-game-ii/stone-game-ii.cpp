class Solution {
public:
    int f(int turn,int idx,int M,vector<int>&piles,
    vector<vector<vector<int>>>&dp){
        int n = piles.size();
        if(idx >= n) return 0;
        int stone = 0;
        int result;
        if(turn == 1)result = -1e9;
        else
        result = 1e9;
        if(dp[turn][idx][M] != -1) return dp[turn][idx][M];
        for(int x =1;x<= min(2*M,n-idx); x++){
            stone += piles[idx+x-1];
            if(turn == 1)
            result = max(result,stone + f(0,idx+x,max(M,x),piles,dp));
            else
            result = min(result,f(1,idx+x,max(M,x),piles,dp));
        }
        return dp[turn][idx][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int M =1;
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return f(1,0,M,piles,dp);
    }
};