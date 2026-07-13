class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,-1},{0,1}};
    int n,m;
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col] = 1;
        for(vector<int>&dir : directions){
            int newRow = row + dir[0];
            int newCol = col + dir[1];
            if(newRow >=0 && newRow <n && newCol>=0 && newCol <m && !vis[newRow][newCol] && grid[newRow][newCol]=='1'){
                dfs(newRow,newCol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
        int cnt =0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row = 0;row<n;row++){
            for(int col =0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    dfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};