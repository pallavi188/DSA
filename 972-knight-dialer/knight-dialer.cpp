class Solution {
public:
    int mod = 1e9+7;
    //adjList
    vector<vector<int>>adj = {
         {4,6},
         {6,8},
         {7,9},
         {4,8},
         {0,3,9},
         {},
         {1,7,0},
         {2,6},
         {1,3},
         {2,4}
    };
    int f(int n,int cell,vector<vector<int>>&dp){
        if(n == 0) return 1;
        int res = 0;
        if(dp[n][cell] != -1) return dp[n][cell];
        for(int &nextCell : adj[cell]){
            res = (res + f(n-1,nextCell,dp))%mod;
        }
        return dp[n][cell] = res;
    }
    int knightDialer(int n) {
        int ans = 0;
        vector<vector<int>>dp(n+1,vector<int>(10,-1));
        for(int cell=0;cell<=9;cell++){
            ans = (ans + f(n-1,cell,dp))%mod;
        }
        return ans;
    }
};