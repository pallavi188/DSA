class Solution {
public:
    int mod = 1e9+7;
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        //adjList
        unordered_map<int,vector<pair<int,int>>>adjList;
        for(auto &it : roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        vector<ll>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            int node = pq.top().second;
            ll dis = pq.top().first;
            pq.pop();
            if(dis > dist[node]) continue;
            for(auto &n : adjList[node]){
                int adjNode = n.first;
                ll d = n.second;
               
                if(d + dis < dist[adjNode]){
                    dist[adjNode] = d+dis;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode],adjNode});

                }
                  //found another path with same shorter distance
                  else if(dis + d == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                  }
            }
        }
        return ways[n-1] % mod;
    }
};