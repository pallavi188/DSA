class Solution {
public:
int mod = 1e9+7;
    int maxDepth(unordered_map<int,vector<int>>&adj,int node,int parent){
        int depth =0;
        for(int &ngbr : adj[node]){
            if(ngbr == parent) continue;
            depth = max(depth,maxDepth(adj,ngbr,node) + 1);
        }
        return depth;
    }
    long long power(long long base,long long exponent){
        if(exponent == 0) return 1;
        long long half = power(base,exponent/2);
        long long result = (half*half)%mod;
        if(exponent%2 == 1)result = (result * base)%mod;
        return result; 
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        //adj list
        unordered_map<int,vector<int>>adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d = maxDepth(adj,1,-1);
        return power(2,d-1);
    }
};