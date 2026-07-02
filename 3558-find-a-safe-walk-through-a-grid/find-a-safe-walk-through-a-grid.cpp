class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>cost(m,vector<int>(n,-1e9));
        cost[0][0] = health-grid[0][0];
        priority_queue<pair<int,pair<int,int>>>pq;
        pq.push({cost[0][0],{0,0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            if(it.first<1){
                break;
            }
            if(it.second.first == m-1 && it.second.second == n-1)return true;
            for(vector<int>& dir:directions){
                int new_i = it.second.first + dir[0];
                int new_j = it.second.second + dir[1];
                if(new_i>=0 && new_i<m && new_j>=0&&new_j<n){
                    int val = it.first - grid[new_i][new_j];
                    if(val > cost[new_i][new_j]){
                        cost[new_i][new_j] = val;
                        pq.push({val,{new_i,new_j}});
                    }
                }
            }
        }
        return false;
    }
};