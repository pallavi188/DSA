class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int n = grid.size();
         int m = grid[0].size();
         queue<pair<pair<int,int>,int>>q;
        
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                q.push({{i,j},0});
              
                }
            }
         }
         int time = 0;
         int dr[] = {-1,1,0,0};
         int dc[] = {0,0,1,-1};
         while(!q.empty()){
            int curr_row = q.front().first.first;
            int curr_col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time,t);
            for(int i=0;i<4;i++){
                int new_row = curr_row + dr[i];
                int new_col = curr_col + dc[i];
                if(new_row>=0 && new_row<n && new_col>=0 && new_col < m && 
                   grid[new_row][new_col] == 1 ){
                    q.push({{new_row,new_col},t+1});
                    grid[new_row][new_col] = 2;
                }
            }
         }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1) return -1;
            }
         }
         return time;
    }
};
