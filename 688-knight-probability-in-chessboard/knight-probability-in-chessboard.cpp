class Solution {
public:
    double f(int r,int c,int k,int n,vector<vector<vector<double>>>&dp){
        if(r<0 || r>=n || c<0 || c>=n) return 0;
        if(k == 0) return 1;
        double res = 0;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        vector<pair<int,int>>directions = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        for(auto dir : directions){
            int newRow = r + dir.first;
            int newCol = c + dir.second;
            res += (double)f(newRow,newCol,k-1,n,dp);
        }
        return dp[r][c][k] = (double)(res/8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n+1,vector<vector<double>>(n+1,vector<double>(k+1,-1)));
        return f(row,column,k,n,dp);
    }
};