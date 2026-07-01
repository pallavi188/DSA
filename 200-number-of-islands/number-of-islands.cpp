class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,-1},{0,1}};
    int n,m;
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int curr_row = q.front().first;
            int curr_col = q.front().second;
            q.pop();
            //traverse all its neighbours and push them in the queue if not visited
            for(vector<int>&dir : directions){
                int new_row = curr_row + dir[0];
                int new_col = curr_col + dir[1];
                if(new_row>=0 && new_row < n && new_col>=0 && new_col < m && !vis[new_row][new_col]&&grid[new_row][new_col]=='1'){
                    vis[new_row][new_col] = 1;
                    q.push({new_row,new_col});
                }
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
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};