class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      //queue -> {row,col,time}
      queue<pair<pair<int,int>,int>>q;
     
      //push those cell in the queue which contain  rotten oranges
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
            }
        }
      }
      int time = 0;
      int dr[] = {-1,1,0,0};
      int dc[] = {0,0,-1,1};
      while(!q.empty()){
        int cur_row = q.front().first.first;
        int cur_col = q.front().first.second;
        int t = q.front().second;
        q.pop();
        time = max(time,t);
        for(int i=0;i<4;i++){
            int newRow = cur_row + dr[i];
            int newCol = cur_col + dc[i];

            //check the validity of each row 
            if(newRow>=0 && newRow < n && newCol>=0 && newCol < m && grid[newRow][newCol] == 1){
                q.push({{newRow,newCol},t+1});
                grid[newRow][newCol] = 2;
            }
        }
      }
      //check if there is any cell which contain fresh orange or not
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1)return -1;
        }
      }
      return time;
    }
};
