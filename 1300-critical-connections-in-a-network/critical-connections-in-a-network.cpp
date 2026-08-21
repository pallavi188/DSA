class Solution {
public:
    int time;
    vector<int>dt,low;
    void dfs(int u,int parU,vector<bool>&vis,vector<vector<int>>&adj,vector<vector<int>>&ans){
             vis[u] = true;
             dt[u] = low[u] = ++time;
             for(int i=0;i<adj[u].size();i++){
                int v = adj[u][i];
                if(!vis[v]){
                    dfs(v,u,vis,adj,ans);
                    //update its low
                    low[u] = min(low[u],low[v]);
                    //bridge condition
                    if(low[v] > dt[u]) ans.push_back({u,v});
                }else if(v != parU){
                    low[u] = min(low[u],dt[v]);
                }
             }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time = 0;
        dt.resize(n);
        low.resize(n);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,-1,vis,adj,ans);
            }
        }
        return ans;
    }
};