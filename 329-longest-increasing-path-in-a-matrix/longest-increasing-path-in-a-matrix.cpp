class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        int m =matrix.size();
        int n = matrix[0].size();

        int ans=1;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        if(dp[i][j] != -1) return dp[i][j];
        for(int k=0;k<4;k++){
            int nr = i + dr[k];
            int nc = j + dc[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && matrix[nr][nc]>matrix[i][j]){
                ans = max(ans,1 + dfs(nr,nc,matrix,dp));
            }
        }
        return dp[i][j] =  ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans,dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};