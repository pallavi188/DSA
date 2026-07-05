class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<vector<int>>&res,vector<int>&temp,int src,int tar){
        temp.push_back(src);
        if(src == tar) res.push_back(temp);
        else{
            for(int &it : graph[src]){
                 dfs(graph,res,temp,it,tar);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        int n = graph.size();
        vector<int>temp;
        dfs(graph,res,temp,0,n-1);
        return res;
    }
};