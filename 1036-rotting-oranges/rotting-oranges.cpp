class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //queue store in the form of {{row,col},time}
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        //taking the rotten oranges in the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }else{
                    vis[i][j] = 0;
                }
            }
        }
        int time =0;
        while(!q.empty()){
            int cur_row = q.front().first.first;
            int cur_col = q.front().first.second;
            int t = q.front().second;
            time = max(time,t);
            q.pop();
            for(vector<int>&dir : directions){
                int new_row = cur_row + dir[0];
                int new_col = cur_col + dir[1];
                if(new_row >=0 && new_row < n && new_col >= 0 && new_col < m
                && vis[new_row][new_col] != 2 && grid[new_row][new_col] == 1){
                    q.push({{new_row,new_col},t+1});
                    vis[new_row][new_col] = 2;
                }
            }
        }
        //check if all the fresh oranges are rotten or not
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};
