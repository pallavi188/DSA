class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>directions = {
       {-1,0},{0,-1},{0,1},{1,0}
    };
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        long long ans = 1;
        int n = grid.size();
        int m = grid[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        for(auto &dir:directions){
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            if(i_>=0 && i_<n && j_>=0 && j_<m && grid[i_][j_] < grid[i][j]){
                ans = (ans + dfs(i_,j_,grid,dp))%mod;
            }
        }
        return dp[i][j]= ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        long long res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 res =(res + dfs(i,j,grid,dp))%mod;
            }
        }
        return res%mod;
    }
};