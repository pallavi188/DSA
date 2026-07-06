class Solution {
public:
    
    long root_result =0;
    int dfs_first(vector<vector<int>>&adj,int curr_node,int prev_node,int curr_depth,
    vector<int>&cnt){
        int total_cnt = 1;
        root_result += curr_depth;
        for(int &child : adj[curr_node]){
            if(child == prev_node)continue;
            total_cnt += dfs_first(adj,child,curr_node,curr_depth+1,cnt);
        }
        cnt[curr_node] = total_cnt;
        return total_cnt;
    }

   void dfs(vector<vector<int>>&adj,int parent_node,int prev_node,vector<int>&result,
   vector<int>&cnt,int n){
    for(int &child : adj[parent_node]){
        if(child == prev_node) continue;
        result[child] = result[parent_node] - cnt[child] + (n-cnt[child]);

        dfs(adj,child,parent_node,result,cnt,n);
    }
   }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       root_result = 0;
       vector<int>cnt(n,0);
       dfs_first(adj,0,-1,0,cnt);
       vector<int>result(n,0);
       result[0] = root_result;
       dfs(adj,0,-1,result,cnt,n);
       return result;
    }
};