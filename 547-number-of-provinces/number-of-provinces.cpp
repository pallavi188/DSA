
class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>adjLs[]){
        vis[node] = 1;
        for(int &it : adjLs[node]){
            if(!vis[it]){
                dfs(it,vis,adjLs);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        //convert adjMatrix into adjList
        vector<int>adjLs[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjLs);
            }
        }
        return cnt;
    }
};