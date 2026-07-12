class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adjList;
        for(auto &it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
        }
        vector<int>distance(n+1,1e9);
        distance[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto &it : adjList[node]){
                int adjNode = it.first;
                int dist = it.second;

                if(dis + dist < distance[adjNode]){
                    distance[adjNode] = dis + dist;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
       int maxi = -1e9;
       for(int i=1;i<=n;i++){
           maxi = max(maxi,distance[i]);
       }
       return (maxi == 1e9) ? -1 : maxi;
    }
};