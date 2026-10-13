class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }
        }
       }
       int dr[]={-1,1,0,0};
       int dc[]={0,0,-1,1};
       int time = 0;
       while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time,t);
        //explore adjacent neighbors
        for(int i=0;i<4;i++){
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            //check validity of new row and new col
            if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && grid[new_r][new_c]==1){
                q.push({{new_r,new_c},t+1});
                grid[new_r][new_c] = 2;
            }
        }
       }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)return -1;
        }
      }
      return time;
    }
};
