class Solution {
public:
    long long dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[r][c] = 1;
        long long sum = grid[r][c];
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if(new_r >=0 && new_r<n && new_c >= 0 && new_c < m && !vis[new_r][new_c]
               && grid[new_r][new_c] > 0){
                sum += dfs(new_r,new_c,grid,vis);
               }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0 && !vis[i][j]){
                long long  sum = dfs(i,j,grid,vis);
                if(sum % k == 0)cnt++;
                }
            }
        }
        return cnt;
    }
};