class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        //adjList formation
        vector<vector<pair<int,double>>>adjList(n);
        for(int i=0;i<edges.size();i++){
           int u = edges[i][0];
           int v = edges[i][1];
           double prob = succProb[i];
           adjList[u].push_back({v,prob});
           adjList[v].push_back({u,prob});
        }
       priority_queue<pair<double,int>>pq;

        vector<double>probablity(n,0);
        probablity[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double p = pq.top().first;
            pq.pop();
            if(p < probablity[node]) continue;
            for(auto &n : adjList[node]){
                int adjNode = n.first;
                double prob = n.second;
                if(p*prob > probablity[adjNode]){
                    probablity[adjNode] = p *prob;
                    pq.push({probablity[adjNode],adjNode});
                }
            }
        }
        return probablity[end_node];
    }
};