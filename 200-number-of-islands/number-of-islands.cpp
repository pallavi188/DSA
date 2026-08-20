class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if(newRow>=0 && newRow < n && newCol>=0 && newCol<m && !vis[newRow][newCol] 
            && grid[newRow][newCol] == '1'){
                dfs(newRow,newCol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int r =0;r<n;r++){
            for(int c = 0;c<m;c++){
                if(!vis[r][c] && grid[r][c] == '1'){
                    cnt++;
                    dfs(r,c,vis,grid);
                }
            }
        }
        return cnt;
    }
};