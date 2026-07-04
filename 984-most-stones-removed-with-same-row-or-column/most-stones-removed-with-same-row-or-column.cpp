class Solution {
public:
    void dfs(int idx,vector<vector<int>>& stones,vector<bool>&vis){
        vis[idx] = true;
        for(int i=0;i<stones.size();i++){
            if((!vis[i]) && (stones[i][0]==stones[idx][0] || stones[i][1] == stones[idx][1])){
                dfs(i,stones,vis);
                vis[i] = true;
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>vis(n,false);
        int grp = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               grp++;
               dfs(i,stones,vis);
            }
        }
        return (n-grp);
    }
};