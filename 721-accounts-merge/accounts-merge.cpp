class DisjointSet{
     vector<int>rank,parent;
     public:
     DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
     }
        int findUParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUParent(parent[node]);
        }
        void unionByRank(int u , int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        
     }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        //step 1 giving node number to att the elements of the account
        unordered_map<string ,int>mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }else{
                    ds.unionByRank(i,mapMailNode[mail]);
                }
            }
        }
        //step 2 merge nodes to their ultimate parent
        vector<string>mergeMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergeMail[node].push_back(mail);
        }
        //step 3 form answer 
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};