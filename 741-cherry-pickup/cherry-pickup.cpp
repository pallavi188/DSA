class Solution {
public:
    int f(int r1,int c1,int r2,vector<vector<int>>&grid,
    vector<vector<vector<int>>>&dp){
        int n= grid.size();
        int c2 = r1+c1-r2;
        //base case
        if(r1 >= n || c1>=n || r2>=n || c2>=n) return -1e9;
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9;
        if(r1 == n-1 && c1 ==n-1) return grid[r1][c1];
        int cherry =0;
        if(r1 == r2 && c1==c2) cherry += grid[r1][c1];
        else
        cherry += grid[r1][c1] + grid[r2][c2];
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int best = max({
            f(r1+1,c1,r2+1,grid,dp),
            f(r1+1,c1,r2,grid,dp),
            f(r1,c1+1,r2+1,grid,dp),
            f(r1,c1+1,r2,grid,dp)
        });
        return dp[r1][c1][c2] = cherry + best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = max(0,f(0,0,0,grid,dp));
        return ans;
    }
};