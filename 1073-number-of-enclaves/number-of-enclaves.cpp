class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid){
        vis[row][col] = 1;
        for(vector<int>&dir : directions){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row>=0 && new_row<n && new_col>=0 && new_col<m && !vis[new_row][new_col] && grid[new_row][new_col]==1)
            {
                dfs(new_row,new_col,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //finding the boundaries 1
        //traversing 1st row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        //traversing first col and last col
        for(int i=0;i<n;i++){
           if(!vis[i][0] && grid[i][0]==1){
            dfs(i,0,vis,grid);
           }
           if(!vis[i][m-1] && grid[i][m-1]==1){
            dfs(i,m-1,vis,grid);
           }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};