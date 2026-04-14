class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        vector<int> vis(n, 0);
        int minCost = 0,dist=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if(vis[node] == 1)continue;
            vis[node] = 1;
            minCost += wt;
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    dist = abs(points[node][0]-points[j][0])+
                               abs(points[node][1]-points[j][1]);
                    pq.push({dist,j});           
                }
            }
        }
        return minCost;
    }
};