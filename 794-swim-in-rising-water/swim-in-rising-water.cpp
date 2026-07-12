class Solution {
public:
    vector<vector<int>>direction{{1,0},{-1,0},{0,1},{0,-1}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty()){
            int t = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(auto &dir : direction){
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                    if(newRow <0 || newRow >=n || newCol <0 || newCol >=n)continue;

                    int newDist = max(grid[newRow][newCol],dist[row][col]);
                    if(newDist < dist[newRow][newCol]){
                        dist[newRow][newCol] = newDist;
                        pq.push({newDist,{newRow,newCol}});
                    }
                
            } 
        }
        return dist[n-1][n-1];
    }
};