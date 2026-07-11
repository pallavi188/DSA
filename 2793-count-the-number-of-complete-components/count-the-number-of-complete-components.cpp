class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&adjList,vector<bool>&visited,vector<int>&comp){
        visited[node] = true;
        comp.push_back(node);
        for(auto &neighborNode : adjList[node]){
            if(!visited[neighborNode]){
                
                dfs(neighborNode,adjList,visited,comp);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //convert into adj list
         unordered_map<int,vector<int>>adjList;
         for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
         }
         vector<bool>visited(n+1,false);
         int cntComponent = 0;
         for(int i=0;i<n;i++){
           
            if(!visited[i]){
                vector<int>comp;
                dfs(i,adjList,visited,comp);
                
                bool isComplete = true;
                for(int u : comp){
                    if(adjList[u].size() != comp.size()-1){
                        isComplete = false;
                        break;
                    }
                }
                if(isComplete) cntComponent++;
            }
         }
         return cntComponent;
    }
};