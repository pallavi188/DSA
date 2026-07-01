
class Solution {
public:
void dfs(int i,vector<int>adjLs[],vector<int>&vis){
    vis[i] = 1;
    for(auto it : adjLs[i]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        //convert the adj matrix into adj list
        vector<int>adjLs[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i !=j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
                }
            }
        }
        vector<int>vis(v,0);
        int cnt = 0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjLs,vis);
            }
        }
        return cnt;
    }
};