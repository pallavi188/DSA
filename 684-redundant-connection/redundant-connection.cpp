class DisjointSet{
    public:
    vector<int>rank,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node])return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int node1 , int node2){
        int ult_node1 = findUParent(node1);
        int ult_node2 = findUParent(node2);
        if(ult_node1 == ult_node2) return;
        if(rank[ult_node1] < rank[ult_node2]) parent[ult_node1] = ult_node2;
        else if(rank[ult_node2] < rank[ult_node1]){
            parent[ult_node2] = ult_node1;
        }
        else{
            parent[ult_node2] = ult_node1;
            rank[ult_node1]++;
        }
    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size();
        DisjointSet ds(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            if(ds.findUParent(u)==ds.findUParent(v)){
                ans.push_back(u);
                ans.push_back(v);
                break;
            }else{
                ds.unionByRank(u,v);
            }
        }
        return ans;
    }
};