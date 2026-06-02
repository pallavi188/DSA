class Solution {
public:
int mod = 1e9+7;
    int f(int sr,int sc,int maxMove,int m,int n,vector<vector<vector<int>>>&dp){
        if(sr<0 || sr>=m || sc<0 || sc>=n)return 1;

        if(maxMove == 0){
             return 0;
        }
        if(dp[sr][sc][maxMove] != -1) return dp[sr][sc][maxMove];

        int up = f(sr-1,sc,maxMove-1,m,n,dp);
        int down = f(sr+1,sc,maxMove-1,m,n,dp);
        int left = f(sr,sc-1,maxMove-1,m,n,dp);
        int right = f(sr,sc+1,maxMove-1,m,n,dp);
        long long ans = (1LL*up + down + left + right)%mod;
        return dp[sr][sc][maxMove] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return f(startRow,startColumn,maxMove,m,n,dp);
    }
};